#include <iostream>
#include <array>
using namespace std;


bool palindromo(const string &texto, int index_front, int index_end){
    if(texto.size()%2 ==0){
        if((index_front+1)==index_end){
            if(texto.at(index_front)==texto.at(index_end)){
                return true;
            }else{
                return false;
            }
        }else{
            if(texto.at(index_front)==texto.at(index_end)){
                return palindromo(texto,index_front+1,index_end-1);
            }else{
                return false;
            }
        }
    }else{
        if(index_front==index_end){
            return true;
        }else{
            if(texto.at(index_front)==texto.at(index_end)){
                return palindromo(texto,index_front+1,index_end-1);
            }else{
                return false;
            }
        }
    }
}

array<int,6> sort(const array<int,6> &a,int index_0,int index_1){

    if(a.at(index_0)>a.at(index_1)){
        array<int,6> a_=a;
        int aux=a_.at(index_1);
        a_.at(index_1)=a_.at(index_0);
        a_.at(index_0)=aux;
        return sort(a_,0,1);
    }else{
        if(index_1==a.size()-1){
            return a;
        }else{
            return sort(a,index_0+1,index_1+1);
        }
    }
}

int main()
{

    string texto {"reconocer"};
    if(palindromo(texto,0,static_cast<int>(texto.size())-1)){
        cout<<"\nEl texto \""<<texto<<"\" es palindromo\n\n";
    }else{
        cout<<"\nEl texto \""<<texto<<"\" no es palindromo\n\n";
    }

    array<int,6> numeros{8,5,4,2,1};
    array<int,6> orden = sort(numeros,0,1);

    cout<<"\nNumeros: \n";
    for(const int &num:numeros){
        cout<<" "<<num;
    }
    cout<<"\n\nOrdenados Menor >> Mayor \n";
    for(const int &num:orden){
        cout<<" "<<num;
    }
    cout<<"\n\n";
    return 0;
}

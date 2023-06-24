#include <iostream>
#include <array>
using namespace std;

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

long int factorial(int numero,int multiplicador){
    if(numero==1){
        return 1;
    }else{
        if(multiplicador==1){
            return numero;
        }else{
            return factorial((numero*multiplicador),multiplicador-1);
        }
    }
}

bool isFibonacci(int numero,int n0,int n1){
    int resultado = n0+n1;
    if(numero==0 || numero ==1){
        return true;
    }else if(resultado>numero){
        return false;
    }else if (resultado == numero){
        return true;
    }else{
        return (isFibonacci(numero,n1,resultado));
    }
}

int main()
{
    /*8,1,2,5,9,4*/
    array<int,6> numeros;numeros.fill(0);
    cout<<"\n DAME 5 numeros:\n";
    for(int i=0;i<numeros.size();i++){
        cin>>numeros.at(i);
    }
    system("cls");
    array<int,6> orden = sort(numeros,0,1);
    cout<<"\nNumeros: \n";
    for(const int &num:numeros){
        cout<<" "<<num;
    }
    cout<<"\n\nOrdenados Menor >> Mayor \n";
    for(const int &num:orden){
        cout<<" "<<num;
    }
    cout<<"\n\nOrdenados Mayor >> Menor \n";
    for(int i=static_cast<int>(orden.size())-1;i>=0;i--){
        cout<<" "<<orden.at(i);
    }
    cout<<"\n\nFactoriales \n";
    for(int i=0;i<orden.size();i++){
        cout<<"\n"<<orden.at(i)<<"! = "<<factorial(orden.at(i),(orden.at(i)-1));
    }
    cout<<"\n\nPertenece a Fibonacci\n";
    for(int i=0;i<orden.size();i++){
        if(isFibonacci(orden.at(i),0,1)==true){
            cout<<"\n"<<orden.at(i)<<" pertenece a la serie de Fibonacci";
        }else{
            cout<<"\n"<<orden.at(i)<<" no pertenece a la serie de Fibonacci";
        }
    }
    cout<<"\n\n";
    return 0;
}

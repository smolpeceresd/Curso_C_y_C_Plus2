#include <iostream>
#include <vector>
#include <array>

using namespace std;

float Suma(const vector<float> &conjunto, float num0,int index){
    if(index==conjunto.size()-1){
        return num0+conjunto.at(index);
    }else{
        float resultado= num0+conjunto.at(index);
        return Suma(conjunto,resultado,index+1);
    }
}

float Resta(const vector<float> &conjunto,float num0, int index){
    if(index==conjunto.size()-1){
        return num0-conjunto.at(index);
    }else{
        float resultado;
        if(index==0){
            resultado= conjunto.at(index)- num0;
        }else{
            resultado = num0-conjunto.at(index);
        }
        return Resta(conjunto,resultado,index+1);
    }
}

float Min(const vector<float> &conjunto,int index, int min){
    if(index==conjunto.size()-1){
        if(conjunto.at(index)<conjunto.at(min)){
            return conjunto.at(index);
        }else{
            return conjunto.at(min);
        }
    }else{
        if(conjunto.at(index)<conjunto.at(min)){
            return Min(conjunto,index+1,index);
        }else{
            return Min(conjunto,index+1,min);
        }
    }
}

float Max(const vector<float> &conjunto,int index, int max){
    if(index==conjunto.size()-1){
        if(conjunto.at(index)>conjunto.at(max)){
            return conjunto.at(index);
        }else{
            return conjunto.at(max);
        }
    }else{
        if(conjunto.at(index)>conjunto.at(max)){
            return Max(conjunto,index+1,index);
        }else{
            return Max(conjunto,index+1,max);
        }
    }
}

void printConjunto(const vector<float> &conjunto){
    cout<<"\n\n Conjunto{ ";
    for(const float &numero:conjunto){
        cout<<numero<<" ";
    }
    cout<<"};";
}

int main()
{
    vector<float> a{1.1,2.2,3.3},b{3.3,5.5},c{1.1,1.1,1.1,1.1};
    array<vector<float>,3> matriz{a,b,c};
    for(int i=0; i<matriz.size();i++){
        printConjunto(matriz.at(i));
        cout<<"\nLa suma del conjunto es: "<<Suma(matriz.at(i),0.0,0);
        cout<<"\nLa resta del conjunto es: "<<Resta(matriz.at(i),0.0,0);
        cout<<"\nEl minimo del conjunto es: "<<Min(matriz.at(i),1,0);
        cout<<"\nEl maximo del conjunto es: "<<Max(matriz.at(i),1,0);
    }
    cout<<"\n\n";
    return 0;
}

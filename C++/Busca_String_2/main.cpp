#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


vector<int> Buscador(const string &texto,const string &palabra){
    vector<int> repeticiones={};
    int max_coincidencia=static_cast<int>(palabra.size()),index{0};
    for(int i=0;i<texto.size();i++){
        if((texto.at(i) == ' ') || (texto.at(i) != palabra.at(index)) ){
            index=0;
        }else if(texto.at(i) == palabra.at(index)){
            index+=1;
            if(index == max_coincidencia){
                repeticiones.push_back(i-(static_cast<int>(palabra.size()-1)));
                index=0;
            }
        }
    }


    return repeticiones;
}

int main()
{
    string palabra;
    string texto = "El rey de Constantinopla esta constantinoplizado.\nConsta que Constanza, no lo pudo desconstantinoplizar.\nEl desconstantinoplizador que desconstantinoplizare al rey de Constantinopla,buen desconstantinoplizador sera.";
    cout<<"\nEl texto a estudiar es el siguiente\n\n"<<texto<<"\n\n";
    cout<<"Que palabra quieres buscar?: ";
    cin>>palabra;
    std::transform(palabra.begin(), palabra.end(), palabra.begin(), ::toupper);
    std::transform(texto.begin(), texto.end(), texto.begin(), ::toupper);
    vector<int> repeticiones=Buscador(texto,palabra);
    if(repeticiones.size()==0){
        cout<<"\nLa palabra "<<palabra<<" no esta en el texto.\n\n";
    }else{
        cout<<"\nPara la palabra: "<<palabra;
        cout<<"\nHay "<<repeticiones.size()<<" coincidencias.";
        cout<<"\nEstas repeticiones se encuentran en las posiciones: ";
        for(const int &elem:repeticiones){
            cout<<elem<<" ";
        }
        cout<<"\n\n";
    }
    return 0;
}

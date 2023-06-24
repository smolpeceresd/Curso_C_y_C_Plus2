#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


vector<int> Buscador( const vector<int> repeticiones,const string &texto,const string &palabra,int index){
    int repeticion= static_cast<int>(texto.find(palabra,index));
    if(repeticion == -1){
        return repeticiones;
    }else{
        vector<int> repeticion_ = repeticiones;
        repeticion_.push_back(repeticion);
        return Buscador(repeticion_,texto,palabra,repeticion+1);
    }
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
    vector<int> repeticiones=Buscador({},texto,palabra,0);
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

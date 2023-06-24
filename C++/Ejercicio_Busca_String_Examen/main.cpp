#include <iostream>
#include <vector>
using namespace std;


bool buscaPalabra(const string &texto2, const string &palabra){
    cout<<"\nBuscando la palabra \""<<palabra<< "\" en el texto \""<<texto2<<"\"";
    int encontrada = texto2.find(palabra,0);
    cout<<"\nEncontrada : "<< encontrada;
    if(encontrada>=0){
        return true;
    }else{
        return false;
    }
}

vector<string> Ejercicio2(const vector<string> &palabras,int index_find,const string texto1,const string texto2){
   // aqui voy a manejar el texto 1 "pepe toma un te"
    int index_hasta_un_espacio=texto1.find(' ',index_find);
    if(index_hasta_un_espacio==-1){// se interpreta como que hemos llegado al final
        bool encontrada = buscaPalabra(texto2,texto1.substr(index_find,texto1.size()-index_find));
        if(encontrada==true){
           int caracteres = texto1.size()-index_find;
           vector<string> palabras_ = palabras;
           palabras_.push_back(texto1.substr(index_find,caracteres));
           return palabras_;
        }else{
            return palabras;
        }
    }else{// tenemos que buscar la palabra
        bool encontrada = buscaPalabra(texto2,texto1.substr(index_find,index_hasta_un_espacio-index_find));
        if(encontrada==true){
           int caracteres = index_hasta_un_espacio-index_find;
           vector<string> palabras_ = palabras;
           palabras_.push_back(texto1.substr(index_find,caracteres));
           return Ejercicio2(palabras_,index_hasta_un_espacio+1,texto1,texto2);
        }else{
            return Ejercicio2(palabras,index_hasta_un_espacio+1,texto1,texto2);
        }
    }
}




int main()
{
    string texto1="Hola, soy Marta, y tu?",texto2="soy el profesor de programacion y soy una zorra";
    cout<<"\n Texto 1 : "<< texto1;
    cout<<"\n Texto 2: "<<texto2;
    vector<string> palabras = Ejercicio2({},0,texto1,texto2);
    if(palabras.size()>=1){
        cout<<"\n Las palabras coindicentes son: ";
        for(const string &texto:palabras){
            cout<<"\n * "<<texto;
        }
    }else{
        cout<<"\nNo coincide ninguna palabra";
    }
    cout<<"\n\n";
}

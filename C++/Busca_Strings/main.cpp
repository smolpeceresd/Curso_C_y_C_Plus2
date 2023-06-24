#include <iostream>
#include <vector>
using namespace std;



/* Cuanta letras */

bool findVector(const vector<char> &v, char letra){
    for(const char &letra_vector:v){
        if(letra_vector == letra){
            return true;
        }
    }
    return false;
}

int cuentaLetras(const string &texto){
    vector<char> letras;

    for(const char &letra:texto){
        if(findVector(letras,letra)==false){
            letras.push_back(letra);
        }
    }

    cout<<"\nLetras\n";
    for(const char &elem:letras){
        cout<<elem;
    }

    return letras.size();
}


/* Obtener todas las palabras */

vector<string> getPalabras(const vector<string> & palabras,const string &texto, int index){
    // se deben observar dos casos el punto y el espacio
    int index_espacio= static_cast<int>(texto.find(' ',index));
    int index_punto = static_cast<int>(texto.find('.',index));
    vector<string> palabras_ = palabras;
    int cantidad_chars;
    if(index_espacio == -1 && (index_punto == texto.size()-1)){ // caso de éxito, estamos al final
        cantidad_chars = index_punto-index;
        palabras_.push_back(texto.substr(index,cantidad_chars));
        return palabras_;
    }else{
        if(index_espacio < index_punto){// antes va el espacio
            cantidad_chars=index_espacio-index;
            palabras_.push_back(texto.substr(index,cantidad_chars));
            return getPalabras(palabras_,texto,index_espacio+1);
        }else{
            cantidad_chars=index_punto-index;
            palabras_.push_back(texto.substr(index,cantidad_chars));
            return getPalabras(palabras_,texto,index_punto+2); // sumo 2 porque he de pasar el espacio siguiente
        }
    }
}


/* Palabra mas larga o corta */

string getPalabra(const vector<string> &palabras, int Larga_corta){

   string palabra_;
   for(int i =0 ; i < palabras.size();i++){
       if (i == 0 ){
           palabra_=palabras.at(i);
       }else{
           if(Larga_corta == 1){// busco la larga
               if(palabras.at(i).size()>palabra_.size()){
                   palabra_=palabras.at(i);
               }
           }else{
               if(palabras.at(i).size()<palabra_.size()){
                   palabra_=palabras.at(i);
               }
           }
       }
   }
    return palabra_;
}



int main()
{
    string texto{"el rey de constantinopla esta constantinoplizado. consta que constanza, no lo pudo desconstantinoplizar. el desconstantinoplizador que desconstantinoplizare al rey de constantinopla buen desconstantinoplizador sera."};

    /** Ejercicio 1 **/

    cout<<"\n\t texto \n\n"<<texto<<"\n\n";
    int cantidad_letras=cuentaLetras(texto);

    vector<string> palabras= getPalabras({},texto,0);

    cout <<"\nCantidad de chars: "<< cantidad_letras;
    cout<<"\nCantidad de palabras : "<<palabras.size();
    string palabra_larga=getPalabra(palabras,1),palabra_corta=getPalabra(palabras,0);
    cout<<"\nPalabra mas larga : \""<<palabra_larga <<"\" numero de letras : "<< palabra_larga.size();
    cout<<"\nPalabra mas corta : \""<<palabra_corta <<"\" numero de letras : "<< palabra_corta.size();


    cout<<"\n\n";


    return 0;
}

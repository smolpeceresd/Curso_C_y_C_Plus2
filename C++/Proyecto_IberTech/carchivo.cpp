#include "carchivo.h"

template <typename T>
CArchivo<T>::CArchivo(const string & nombre_archivo) : CObject<T>(nombre_archivo) {}

template<typename T>
CArchivo<T>::~CArchivo()
{

}

template <typename T>
CDiccionario<int> CArchivo<T>::getDiccionario_Palabras() const
{
    return diccionario_Palabras;
}

template <typename T>
void CArchivo<T>::setDiccionario_Palabras(const CDiccionario<int> &newDiccionario_Palabras)
{
    diccionario_Palabras = newDiccionario_Palabras;
}


template<typename T>
void CArchivo<T>::serializacion(const int read_write) const
{
    if(read_write == 1){// read
        ifstream fichero; fichero.open(this->getDato(),ios::in | ios::binary);

        if(!fichero){
            cout<<"no se puede abrir";
        }
        string linea;
        while(getline(fichero,linea)){
            this->getDiccionario_Palabras().addPalabras(linea);
        }

        fichero.close();

    }else{//write

    }
}




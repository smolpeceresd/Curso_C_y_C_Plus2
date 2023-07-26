#include "cdiccionario.h"

template<typename T>
CDiccionario<T>::CDiccionario():CObject<T>(0)
{

}

template<typename T>
CDiccionario<T>::~CDiccionario()
{

}

template<typename T>
map<string, CPalabras<string> > CDiccionario<T>::getMapa_palabras() const
{
    return mapa_palabras;
}

template<typename T>
void CDiccionario<T>::setMapa_palabras(const map<string, CPalabras<string> > &newMapa_palabras)
{
    mapa_palabras = newMapa_palabras;
}



template<typename T>
void CDiccionario<T>::serializacion(const int read_write) const
{
    cout<<"\nEsta clase no tiene serializacion";
}

template<typename T>
void CDiccionario<T>::print() const
{
    cout<<"\n Numero de palabras en el diccionario: "<<this->getDato();
}

template<typename T>
void CDiccionario<T>::toString() const
{
    this->print();
    cout<<"\n Palabras del diccionario: ";

}











template<typename T>
void CDiccionario<T>::addPalabras(const string &linea)
{
    std::vector<std::string> subcadenas;
    std::stringstream ss(linea);
    std::string subcadena;

    while (std::getline(ss,subcadena,' ')) {
        subcadenas.push_back(subcadena);
    }

    for(int i=0;i<static_cast<int>(subcadenas.size());i++){
        map<string,CPalabras<string>>::iterator it = this->getMapa_palabras().find(subcadenas.at(i));
        if(it != this->getMapa_palabras().end()){
            it->second.incrementcantidad();
        }else{
            CPalabras<string> *nuevaPalabra = new CPalabras<string>(subcadenas.at(i));
            this->getMapa_palabras().insert(pair<string,CPalabras<string>*>(subcadenas.at(i),nuevaPalabra));
        }
    }
}




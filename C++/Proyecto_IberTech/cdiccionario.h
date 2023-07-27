#ifndef CDICCIONARIO_H
#define CDICCIONARIO_H

#include <CObject.h>
#include <CPalabra.h>
#include <iostream>
#include <map>
using namespace std;

template <typename T>
class CDiccionario: public CObject<T>
{

public:
    CDiccionario();
    ~CDiccionario();

    map<string, CPalabra<string> > getMapa_palabras() const;
    void setMapa_palabras(const map<string, CPalabra<string> > &newMapa_palabras);

    void addPalabras(const string & linea);

    void print() const override;
    void toString() const override;
private:
    map<string,CPalabra<string>> mapa_palabras;
    //T getDato() const = delete;
};

template <typename T>
CDiccionario<T>::CDiccionario():CObject<T>(0)
{

}
template <typename T>
CDiccionario<T>::~CDiccionario()
{

}

template <typename T>
map<string, CPalabra<string> > CDiccionario<T>::getMapa_palabras() const
{
    return mapa_palabras;
}

template <typename T>
void CDiccionario<T>::setMapa_palabras(const map<string, CPalabra<string> > &newMapa_palabras)
{
    mapa_palabras = newMapa_palabras;
}

template<typename T>
void CDiccionario<T>::addPalabras(const string &linea)
{


}

template <typename T>
void CDiccionario<T>::print() const
{
    cout<<"\nLa cantidad de palabras que gestiona este Diccionario son: "<<this->getDato();
}

template <typename T>
void CDiccionario<T>::toString() const
{
    this->print();
    if(this->getMapa_palabras().size()>0){

        cout<<"\nPalabras:\n";
        for(const pair<string,CPalabra<string>>& par:this->getMapa_palabras()){
            par.second.toString();
        }
    }else{
        cout<<"\n Todavia no hay palabras registradas";
    }

}

#endif // CDICCIONARIO_H

#ifndef CARCHIVO_H
#define CARCHIVO_H

#include <iostream>
#include <CObject.h>
#include <CDiccionario.h>
using namespace std;

template <typename T>
class CArchivo: public CObject<T>
{
public:
    CArchivo(const T & texto);
    ~CArchivo();

    CDiccionario<int> getDiccionario_palabras() const;
    void setDiccionario_palabras(const CDiccionario<int> &newDiccionario_palabras);
    void escritura(const string & fichero);
    void lectura();

    void print() const override;
    void toString() const override;

private:
    CDiccionario<int> diccionario_palabras;
};

template <typename T>
CArchivo<T>::CArchivo(const T & texto):CObject<T>(texto)
{

}

template <typename T>
CArchivo<T>::~CArchivo()
{

}

template <typename T>
CDiccionario<int> CArchivo<T>::getDiccionario_palabras() const
{
    return this->diccionario_palabras;
}

template <typename T>
void CArchivo<T>::setDiccionario_palabras(const CDiccionario<int> &newDiccionario_palabras)
{
    diccionario_palabras = newDiccionario_palabras;
}

template<typename T>
void CArchivo<T>::escritura(const string &fichero)
{

}

template<typename T>
void CArchivo<T>::print() const
{
    cout<<"\nEl documento que gestiona este objeto es: "<<this->getDato();
}

template<typename T>
void CArchivo<T>::toString() const
{
    this->print();
    this->getDiccionario_palabras().toString();
}


std::ostream& operator<<(std::ostream& os, const CArchivo<string> & archivo){
    archivo.toString();
    return os;
}


std::istream& operator>>(std::istream & is, CArchivo<string> & archivo){
    string documento;
    is>>documento;
    archivo.escritura(documento);
    return is;
}
#endif // CARCHIVO_H

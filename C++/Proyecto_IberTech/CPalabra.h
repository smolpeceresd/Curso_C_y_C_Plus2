#ifndef CPALABRA_H
#define CPALABRA_H

#include <CObject.h>
#include <iostream>

using namespace std;

template <typename T>

class CPalabra: public CObject<T>
{
public:
    CPalabra(const T & palabra);
    ~CPalabra();

    int getContador() const;
    void setContador(int newContador);

    void print() const override;
    void toString() const override;

private:
    int contador;
};


template<typename T>
CPalabra<T>::CPalabra(const T &palabra):CObject<T>(palabra)
{
    this->contador=0;
}

template<typename T>
CPalabra<T>::~CPalabra()
{

}

template <typename T>
int CPalabra<T>::getContador() const
{
    return this->contador;
}
template <typename T>
void CPalabra<T>::setContador(int newContador)
{
    contador = newContador;
}

template<typename T>
void CPalabra<T>::print() const
{
    cout<<"Palabra asignada al objeto: "<<this->getDato();
}

template<typename T>
void CPalabra<T>::toString() const
{
    this->print();
    cout<<"\n Numero de repeticiones: "<<this->getDato();
}

#endif // CPALABRA_H

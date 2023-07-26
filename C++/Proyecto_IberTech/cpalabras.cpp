#include "cpalabras.h"

template <typename T>
CPalabras<T>::CPalabras(const string &palabra):CObject<T>()
{
    this->cantidad=1;
}

template <typename T>
int CPalabras<T>::getCantidad() const
{
    return cantidad;
}
template <typename T>
void CPalabras<T>::setCantidad(int newCantidad)
{
    cantidad = newCantidad;
}

template <typename T>
void CPalabras<T>::incrementcantidad()
{
    this->setCantidad(this->cantidad+1);
}

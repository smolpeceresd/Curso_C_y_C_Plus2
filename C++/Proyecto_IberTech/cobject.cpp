#include "cobject.h"

template<typename T>
CObject<T>::CObject(const T & dato_)
{
    this->dato=dato_;
}

template <typename T>
T CObject<T>::getDato() const
{
    return dato;
}

template <typename T>
void CObject<T>::setDato(const T &newDato)
{
    dato = newDato;
}

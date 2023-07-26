#ifndef CDICCIONARIO_H
#define CDICCIONARIO_H
#include <iostream>
#include <map>
#include <cobject.h>
#include <cpalabras.h>


template <typename T>
class CDiccionario: public CObject<T>
{
public:
    CDiccionario();
    ~CDiccionario();

private:
    map<string,CPalabras<string>> mapa_palabras;
};

#endif // CDICCIONARIO_H

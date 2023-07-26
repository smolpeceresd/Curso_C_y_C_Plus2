#ifndef CDICCIONARIO_H
#define CDICCIONARIO_H
#include <iostream>
#include <map>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <vector>
#include <cobject.h>
#include <cpalabras.h>


template <typename T>
class CDiccionario: public CObject<T>
{
public:
    CDiccionario();
    ~CDiccionario();

    map<string, CPalabras<string> > getMapa_palabras() const;
    void setMapa_palabras(const map<string, CPalabras<string> > &newMapa_palabras);
    void addPalabras(const string & linea);


    virtual void serializacion(const int read_write)const ;
    virtual void print() const;
    virtual void toString() const;


private:
    map<string,CPalabras<string>> mapa_palabras;
};

#endif // CDICCIONARIO_H

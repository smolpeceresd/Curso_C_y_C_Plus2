#ifndef CARCHIVO_H
#define CARCHIVO_H

#include <iostream>
#include <vector>
#include <cdiccionario.h>
#include <cobject.h>
using namespace std;


class CArchivo: public CObject<string>
{
public:
    CArchivo(const string &nombre_archivo, const char read_write );
    ~CArchivo();


private:
    CDiccionario diccionario_Palabras;
};

#endif // CARCHIVO_H

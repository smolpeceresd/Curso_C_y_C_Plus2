#ifndef CARCHIVO_H
#define CARCHIVO_H

#include <iostream>
#include <vector>
#include <cdiccionario.h>
#include <cobject.h>
#include <fstream>
using namespace std;

template <typename T>
class CArchivo : public CObject<T>
{
public:
    CArchivo(const string &nombre_archivo);
    ~CArchivo();

private:
    CDiccionario<int> diccionario_Palabras;

};

#endif // CARCHIVO_H

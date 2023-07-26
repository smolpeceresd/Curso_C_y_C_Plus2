#ifndef CARCHIVO_H
#define CARCHIVO_H

#include <iostream>
#include <vector>
#include <string.h>
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

    void serializacion(const int read_write)const  override;
    void print() const override;
    void toString() const override;



    CDiccionario<int> getDiccionario_Palabras() const;
    void setDiccionario_Palabras(const CDiccionario<int> &newDiccionario_Palabras);

private:
    CDiccionario<int> diccionario_Palabras;

};

#endif // CARCHIVO_H

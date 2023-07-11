#ifndef ACTIVO_H
#define ACTIVO_H
#include <iostream>
#include <parametros.h>
#include <circulante.h>
#include <fstream>
using namespace std;

class Activo : public Parametros, public Circulante
{
public:
    Activo(const string& descripcion_, double monto_,const string &fecha_,bool circulante_no_circulante);
    ~Activo();

    void print(ofstream &fichero)const ;
};
#endif // ACTIVO_H

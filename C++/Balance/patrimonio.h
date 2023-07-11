#ifndef PATRIMONIO_H
#define PATRIMONIO_H

#include <iostream>
#include <parametros.h>
#include <circulante.h>
#include <fstream>
using namespace std;

class Patrimonio: public Parametros, public Circulante
{
public:
    Patrimonio(const string& descripcion_, double monto_,const string &fecha_,bool circulante_no_circulante);
    ~Patrimonio();

    void print(ofstream &fichero) const;
};

#endif // PATRIMONIO_H

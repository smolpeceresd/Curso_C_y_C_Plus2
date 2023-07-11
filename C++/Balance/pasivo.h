#ifndef PASIVO_H
#define PASIVO_H
#include <iostream>
#include <parametros.h>
#include <circulante.h>
#include <fstream>

using namespace std;

class Pasivo : public Parametros, public Circulante
{
public:
    Pasivo(const std::string& descripcion_, double monto_, const string &fecha_, bool circulante_no_circulante);
   ~Pasivo();

    void print(ofstream &fichero) const;
};

#endif // PASIVO_H

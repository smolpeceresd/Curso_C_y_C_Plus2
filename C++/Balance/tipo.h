#ifndef TIPO_H
#define TIPO_H

#include <iostream>

using namespace std;

class Tipo
{
public:
    Tipo(const string &categoria, bool circulante,const string &nombre);
    ~Tipo();

    const string &getNombre() const;
    void setNombre(const string &newNombre);

    const string &getCategoria() const;
    void setCategoria(const string &newCategoria);

    bool getCirculante_no_circulante() const;
    void setCirculante_no_circulante(bool newCirculante_no_circulante);

    void Print() const;
private:
    string nombre,categoria;
    bool circulante_no_circulante;
};

#endif // TIPO_H

#ifndef ACCION_H
#define ACCION_H

#include <iostream>
using namespace std;

class Accion
{
public:
    Accion();
    Accion(int index_accion_,const string &palabras_,const string respuesta_);
    ~Accion();

    int getIndex_accion() const;
    void setIndex_accion(int newIndex_accion);

    const string &getPalabras() const;
    void setPalabras(const string &newPalabras);

    const string &getRespuesta() const;
    void setRespuesta(const string &newRespuesta);

private:
    int index_accion;
    string palabras,respuesta;
};

#endif // ACCION_H

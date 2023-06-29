#include "accion.h"
#include <iostream>
#include <string>
using namespace std;


Accion::Accion()
{

}

Accion::Accion(int index_accion_, const string &palabras_, const string respuesta_)
{
    this->index_accion=index_accion_;
    this->palabras=palabras_;
    this->respuesta=respuesta_;
}

Accion::~Accion()
{
}

int Accion::getIndex_accion() const
{
    return index_accion;
}

void Accion::setIndex_accion(int newIndex_accion)
{
    index_accion = newIndex_accion;
}

const string &Accion::getPalabras() const
{
    return palabras;
}

void Accion::setPalabras(const string &newPalabras)
{
    palabras = newPalabras;
}

const string &Accion::getRespuesta() const
{
    return respuesta;
}

void Accion::setRespuesta(const string &newRespuesta)
{
    respuesta = newRespuesta;
}

#include "parametros.h"


Parametros::Parametros(const string &descripcion_, double monto_, string fecha_)
{
    this->descripcion=descripcion_;
    this->monto=monto_;
    this->fecha=fecha_;
}

Parametros::~Parametros()
{

}

const string &Parametros::getDescripcion() const
{
    return descripcion;
}

void Parametros::setDescripcion(const string &newDescripcion)
{
    descripcion = newDescripcion;
}

double Parametros::getMonto() const
{
    return monto;
}

void Parametros::setMonto(double newMonto)
{
    monto = newMonto;
}

const string &Parametros::getFecha() const
{
    return fecha;
}

void Parametros::setFecha(const string &newFecha)
{
    fecha = newFecha;
}

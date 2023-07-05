#include "vehiculo.h"

Vehiculo::Vehiculo(const string &nombre, const string &marca, int km, int precio)
{
    this->marca=marca;
    this->nombre=nombre;
    this->km=km;
    this->precio=precio;
}

Vehiculo::~Vehiculo()
{

}


const string &Vehiculo::getNombre() const
{
    return nombre;
}

void Vehiculo::setNombre(const string &newNombre)
{
    nombre = newNombre;
}

const string &Vehiculo::getMarca() const
{
    return marca;
}

void Vehiculo::setMarca(const string &newMarca)
{
    marca = newMarca;
}

int Vehiculo::getKm() const
{
    return km;
}

void Vehiculo::setKm(int newKm)
{
    km = newKm;
}

int Vehiculo::getPrecio() const
{
    return precio;
}

void Vehiculo::setPrecio(int newPrecio)
{
    precio = newPrecio;
}

void Vehiculo::printVehiculo() const
{
    cout<<"\nModelo: "<<this->getMarca()<<" "<<this->getNombre()
       <<"\nKm: "<<this->getKm()
      <<"\nPrecio: "<<this->getPrecio();
}


#ifndef VEHICULO_H
#define VEHICULO_H
#include <iostream>

using namespace std;


class Vehiculo
{
public:
    Vehiculo(const string &nombre,const string &marca, int km, int precio);
    ~Vehiculo();

    const string &getNombre() const;
    void setNombre(const string &newNombre);

    const string &getMarca() const;
    void setMarca(const string &newMarca);

    int getKm() const;
    void setKm(int newKm);

    int getPrecio() const;
    void setPrecio(int newPrecio);

    void printVehiculo()const;

private:
    string nombre,marca;
    int km,precio;

};

#endif // VEHICULO_H

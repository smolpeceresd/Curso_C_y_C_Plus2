#ifndef CONCESIONARIO_H
#define CONCESIONARIO_H
#include <iostream>
#include <vector>
#include <vehiculo.h>

using namespace std;

class Concesionario
{
public:
    Concesionario(const string &ubicacion,const vector<string> &marcas,const vector<Vehiculo> &vehiculos);
    ~Concesionario();


    void printVehiculos(const string &marca)const;
    void printVehiculo(const string &marca, const string &modelo,int case_)const;

    const vector<Vehiculo> &getVehiculos() const;
    void setVehiculos(const vector<Vehiculo> &newVehiculos);

    const string &getUbicacion() const;
    void setUbicacion(const string &newUbicacion);

    const vector<string> &getMarcas() const;
    void setMarcas(const vector<string> &newMarcas);

    void printMarcas();


private:
    vector<Vehiculo> vehiculos;
    string ubicacion;
    vector<string> marcas;
};

#endif // CONCESIONARIO_H

#include "concesionario.h"

Concesionario::Concesionario(const string &ubicacion, const vector<string> &marcas, const vector<Vehiculo> &vehiculos)
{
    this->ubicacion=ubicacion;
    this->marcas=marcas;
    this->vehiculos=vehiculos;
}

Concesionario::~Concesionario()
{

}

const vector<Vehiculo> &Concesionario::getVehiculos() const
{
    return vehiculos;
}

void Concesionario::setVehiculos(const vector<Vehiculo> &newVehiculos)
{
    vehiculos = newVehiculos;
}

const string &Concesionario::getUbicacion() const
{
    return ubicacion;
}

void Concesionario::setUbicacion(const string &newUbicacion)
{
    ubicacion = newUbicacion;
}

const vector<string> &Concesionario::getMarcas() const
{
    return marcas;
}

void Concesionario::setMarcas(const vector<string> &newMarcas)
{
    marcas = newMarcas;
}

void Concesionario::printMarcas()
{
    cout<<"\nMarcas: ";
    for(const string &elem:this->getMarcas()){
        cout<<" "<<elem;
    }
}

void Concesionario::printVehiculos(const string &marca) const
{
    for (int i = 0; i < this->getVehiculos().size(); ++i) {
        if(this->getVehiculos().at(i).getMarca()==marca){
            this->getVehiculos().at(i).printVehiculo();
        }
    }
}

void Concesionario::printVehiculo(const string &marca, const string &modelo,int case_) const
{
    for (int i = 0; i < this->getVehiculos().size(); ++i) {
        if(this->getVehiculos().at(i).getMarca()==marca && this->getVehiculos().at(i).getNombre()==modelo){
            if(case_ ==5){
                this->getVehiculos().at(i).printVehiculo();
            }else if(case_ ==3){
                cout<<" El precio del "<<marca<<" "<<modelo<<" es "<<this->getVehiculos().at(i).getPrecio();
            }else if(case_ ==4){
                cout<<" El precio del "<<marca<<" "<<modelo<<" es "<<this->getVehiculos().at(i).getPrecio();
            }
        }
    }
}


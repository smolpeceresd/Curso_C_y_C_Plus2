#ifndef PARAMETROS_H
#define PARAMETROS_H

#include <iostream>
#include <chrono>
using namespace std;

class Parametros
{
public:
    Parametros(const string &descripcion_,double monto_,string fecha_);
    ~Parametros();

    const string &getDescripcion() const;
    void setDescripcion(const string &newDescripcion);

    double getMonto() const;
    void setMonto(double newMonto);

    const string &getFecha() const;
    void setFecha(const string &newFecha);

private:
    string descripcion;
    double monto;
    string fecha;

};

#endif // PARAMETROS_H

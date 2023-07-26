#ifndef CPALABRAS_H
#define CPALABRAS_H
#include <cobject.h>
#include <iostream>
using namespace std;
template <typename T>
class CPalabras: public CObject<T>
{
public:
    CPalabras(const string & palabra);
    ~CPalabras();

    int getCantidad() const;
    void setCantidad(int newCantidad);
    void incrementcantidad();

private:
    int cantidad;
};

#endif // CPALABRAS_H

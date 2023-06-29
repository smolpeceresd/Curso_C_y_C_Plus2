#include "palabra.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Palabra::Palabra()
{
}

Palabra::Palabra(char palabra_[100], int cantidad_)
{
    strcpy(palabra, palabra_);
    cantidad = cantidad_;
    nextPalabra = NULL;
}

Palabra::~Palabra()
{
    printf("\nDestruyendo %s",this->getPalabra());
}

int Palabra::getCantidad() const
{
    return cantidad;
}

void Palabra::setCantidad(int newCantidad)
{
    cantidad = newCantidad;
}

void Palabra::setPalabra(char palabra_[100])
{
    strcpy(palabra, palabra_);
}

char *Palabra::getPalabra() const
{
    return (char *)palabra;
}

Palabra *Palabra::getNextPalabra() const
{
    return nextPalabra;
}

void Palabra::setNextPalabra(Palabra *newNextPalabra)
{
    nextPalabra = newNextPalabra;
}

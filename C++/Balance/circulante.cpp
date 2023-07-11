#include "circulante.h"

Circulante::Circulante(bool circulante_no_circulante)
{
    this->circulante_no_circulante=circulante_no_circulante;
}

Circulante::~Circulante()
{

}

bool Circulante::getCirculante_no_circulante() const
{
    return circulante_no_circulante;
}

void Circulante::setCirculante_no_circulante(bool newCirculante_no_circulante)
{
    circulante_no_circulante = newCirculante_no_circulante;
}


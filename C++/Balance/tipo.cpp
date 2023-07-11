#include "tipo.h"

Tipo::Tipo(const string &categoria, bool circulante, const string &nombre)
{
    this->categoria=categoria;
    this->circulante_no_circulante=circulante;
    this->nombre=nombre;
}

Tipo::~Tipo()
{

}

const string &Tipo::getNombre() const
{
    return nombre;
}

void Tipo::setNombre(const string &newNombre)
{
    nombre = newNombre;
}

const string &Tipo::getCategoria() const
{
    return categoria;
}

void Tipo::setCategoria(const string &newCategoria)
{
    categoria = newCategoria;
}

bool Tipo::getCirculante_no_circulante() const
{
    return circulante_no_circulante;
}

void Tipo::setCirculante_no_circulante(bool newCirculante_no_circulante)
{
    circulante_no_circulante = newCirculante_no_circulante;
}

void Tipo::Print() const
{
    cout<<"Categoria: "<<this->getCategoria()<<" Circulante: "<<this->getCirculante_no_circulante()<<" Nombre: "<<this->getNombre();
}

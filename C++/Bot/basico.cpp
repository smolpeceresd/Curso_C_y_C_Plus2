#include "basico.h"



Basico::Basico(const string tag, const string respuesta)
{
    this->tag=tag;
    this->respuesta=respuesta;
}

Basico::~Basico()
{

}

const string &Basico::getTag() const
{
    return tag;
}

void Basico::setTag(const string &newTag)
{
    tag = newTag;
}

const string &Basico::getRespuesta() const
{
    return respuesta;
}

void Basico::setRespuesta(const string &newRespuesta)
{
    respuesta = newRespuesta;
}

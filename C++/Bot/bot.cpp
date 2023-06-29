#include "bot.h"

Bot::Bot()
{

}

Bot::~Bot()
{
    cout<<"\nBorrando de Bot";
}

const vector<Accion> &Bot::getAcciones() const
{
    return Acciones;
}

void Bot::setAcciones(const vector<Accion> &newAcciones)
{
    Acciones = newAcciones;
}

const vector<Basico> &Bot::getItems_Basicos() const
{
    return Items_Basicos;
}

void Bot::setItems_Basicos(const vector<Basico> &newItems_Basicos)
{
    Items_Basicos = newItems_Basicos;
}

void Bot::addBasico(const Basico &newBasico)
{
    this->Items_Basicos.push_back(newBasico);
}

void Bot::addaccion(const Accion &newAccion)
{
    this->Acciones.push_back(newAccion);
}

void Bot::printBasicos()
{
    cout<<"\n Elementos Basicos: ";
    for(const Basico &basico:this->getItems_Basicos()){
        cout<<"\n"<<basico.getTag()<<": "<<basico.getRespuesta()<<" Memoria: ";
    }
}

void Bot::printAcciones()
{
    cout<<"\n Acciones: ";
    for(const Accion &accion:this->getAcciones()){
        cout<<"\nAccion "<<accion.getIndex_accion()<<"\nPalabras clave: "<<accion.getPalabras()<<"\nRespuesta: "<<accion.getRespuesta();
    }
}

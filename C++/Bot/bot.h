#ifndef BOT_H
#define BOT_H

#include <iostream>
#include <vector>
#include <basico.h>
#include <accion.h>
using namespace std;

class Bot
{
public:
    Bot();
    ~Bot();

    const vector<Accion> &getAcciones() const;
    void setAcciones(const vector<Accion> &newAcciones);

    const vector<Basico> &getItems_Basicos() const;
    void setItems_Basicos(const vector<Basico> &newItems_Basicos);

    void addBasico(const Basico &newBasico);
    void addaccion(const Accion &newAccion);

    void printBasicos();
    void printAcciones();

private:
    vector<Basico> Items_Basicos;
    vector<Accion> Acciones;
};

#endif // BOT_H

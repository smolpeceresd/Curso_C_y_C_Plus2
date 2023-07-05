#ifndef BOT_H
#define BOT_H
#include <iostream>
#include <map>
#include <nodo.h>
#include <structs.h>
using namespace std;
class Bot
{
public:
    Bot();
    ~Bot();


    Nodo *getRaiz() const;
    void setRaiz(Nodo *newRaiz);


    bool buildLista(Nodo *newNodo,int rama, int padre);
    bool AddRama(Nodo *list,Nodo *newNodo,int padre);

    const map<string, string> &getMapa_respuesta() const;
    void setMapa_respuesta(const map<string, string> &newMapa_respuesta);
    void addMapa(const string &clave,const string &valor);
    Decision tomaDeciosiones(const vector<string> &input);
    void printLista()const;

private:
    Nodo *raiz;
    map<string,string> Mapa_respuesta;

};

#endif // BOT_H

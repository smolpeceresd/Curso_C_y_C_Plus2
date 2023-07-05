#ifndef NODO_H
#define NODO_H
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <structs.h>
using namespace std;

class Nodo
{
public:
    Nodo(const vector<string> &palabras, const string &index_respuesta, int id_nodo);
    Nodo();
    ~Nodo();



    Nodo *getNodoIzq() const;
    void setNodoIzq(Nodo *newNodoIzq);

    Nodo *getNodoDrc() const;
    void setNodoDrc(Nodo *newNodoDrc);

    const string &getIndex_respuesta() const;
    void setIndex_respuesta(const string &newIndex_respuesta);

    int getId_nodo() const;
    void setId_nodo(int newId_nodo);

    void printNodo(Nodo * nodo,const map<string,string> &mapa , ofstream &fichero)const;

    const vector<string> &getPalabras() const;
    void setPalabras(const vector<string> &newPalabras);
    void tomaDecisiones(Nodo* nodoEstudio,Decision* decision,const vector<string> &texto);

    vector<string> coincide(const vector<string> &palabras,const vector<string> &texto);

private:
    string index_respuesta;
    vector<string> palabras;
    int id_nodo;
    Nodo *nodoIzq,*nodoDrc;

};

#endif // NODO_H

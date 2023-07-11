#ifndef BALANCE_H
#define BALANCE_H

#include <iostream>
#include <vector>
#include <activo.h>
#include <pasivo.h>
#include <tipo.h>
#include <patrimonio.h>
#include <algorithm>
#include <fstream>

using namespace std;


class Balance
{
public:
    Balance();
    ~Balance();

    const vector<Activo> &getActivos() const;
    void setActivos(const vector<Activo> &newActivos);

    const vector<Pasivo> &getPasivos() const;
    void setPasivos(const vector<Pasivo> &newPasivos);

    const vector<Tipo> &getLista_tipos() const;
    void setLista_tipos(const vector<Tipo> &newLista_tipos);

    const vector<Patrimonio> &getPatrimonio() const;
    void setPatrimonio(const vector<Patrimonio> &newPatrimonio);

    const vector<Patrimonio> &getPatrimonios() const;
    void setPatrimonios(const vector<Patrimonio> &newPatrimonios);

    void addActivo(const Activo & activo);
    void addPasivo(const Pasivo & pasivo);
    void addLista(const Tipo & tipo);
    void addPatrimonio(const Patrimonio & patrimonio);
    void printLista()const;
    void calculaBalance()const;

private:
    vector<Tipo> Lista_tipos;
    vector<Activo> Activos;
    vector<Pasivo> Pasivos;
    vector<Patrimonio> Patrimonios;


};

#endif // BALANCE_H

#include "balancesheet.h"
#include <iostream>
#include <string>
using namespace std;
Balancesheet::Balancesheet(string name)
{
    this->whoami=name;
    this->iValorTotal=0;
}

Balancesheet::Balancesheet(int iBalance,string name)
{
    this->iValorTotal=iBalance;
    this->whoami=name;
}



Balancesheet::~Balancesheet()
{
    cout<<"\n"<<this->getName()<<" se derrite\n";
}


int Balancesheet::getValorPrivado(){
    return this->valorPrivado;
}

int Balancesheet::getValorProtegido(){
    return this->valorProtegido;
}

int Balancesheet::getIValorTotal(){
    return this->iValorTotal;
}

string Balancesheet::getName(){
    return this->whoami;
}

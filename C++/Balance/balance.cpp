#include "balance.h"

Balance::Balance()
{

}

Balance::~Balance()
{

}

const vector<Activo> &Balance::getActivos() const
{
    return Activos;
}

void Balance::setActivos(const vector<Activo> &newActivos)
{
    Activos = newActivos;
}

const vector<Pasivo> &Balance::getPasivos() const
{
    return Pasivos;
}

void Balance::setPasivos(const vector<Pasivo> &newPasivos)
{
    Pasivos = newPasivos;
}

void Balance::addActivo(const Activo &activo)
{
    this->Activos.push_back(activo);
}

void Balance::addPasivo(const Pasivo &pasivo)
{
    this->Pasivos.push_back(pasivo);
}

void Balance::addLista(const Tipo &tipo)
{
    this->Lista_tipos.push_back(tipo);
}

void Balance::addPatrimonio(const Patrimonio &patrimonio)
{
    this->Patrimonios.push_back(patrimonio);
}

void Balance::printLista() const
{
    for(const Tipo &tipo:this->getLista_tipos()){
        cout<<"\n";tipo.Print();
    }
}

void Balance::calculaBalance() const
{
    /*Fichero para lectura de balance*/
    ofstream fichero;fichero.open("Balance.txt",ios::out | ios::trunc);

    vector<Activo> a=this->getActivos();vector<Pasivo> p=this->getPasivos(); vector<Patrimonio>pa=this->getPatrimonios();
    std::sort(a.begin(), a.end(), [](const Activo& elemento1, const Activo& elemento2) {
        if (elemento1.getCirculante_no_circulante() == 1 && elemento2.getCirculante_no_circulante() == 0) {
            return true;
        } else if (elemento1.getCirculante_no_circulante() == 0 && elemento2.getCirculante_no_circulante() == 1) {
            return false;
        } else {
            return elemento1.getMonto() < elemento2.getMonto();
        }
    });
    std::sort(p.begin(), p.end(), [](const Pasivo& elemento1, const Pasivo& elemento2) {
        if (elemento1.getCirculante_no_circulante() == 1 && elemento2.getCirculante_no_circulante() == 0) {
            return true;
        } else if (elemento1.getCirculante_no_circulante() == 0 && elemento2.getCirculante_no_circulante() == 1) {
            return false;
        } else {
            return elemento1.getMonto() < elemento2.getMonto();
        }
    });
    std::sort(pa.begin(), pa.end(), [](const Patrimonio& elemento1, const Patrimonio& elemento2) {
        if (elemento1.getCirculante_no_circulante() == 1 && elemento2.getCirculante_no_circulante() == 0) {
            return true;
        } else if (elemento1.getCirculante_no_circulante() == 0 && elemento2.getCirculante_no_circulante() == 1) {
            return false;
        } else {
            return elemento1.getMonto() < elemento2.getMonto();
        }
    });
    double totalAct=0,totalPasivo=0,totalPatrimonio=0;

    for(const Activo &elem:a){
        elem.print(fichero);
        totalAct+=elem.getMonto();
    }
    for(const Pasivo &elem:p){
        elem.print(fichero);
        totalPasivo+=elem.getMonto();
    }
    for(const Patrimonio &elem:pa){
        elem.print(fichero);
        totalPatrimonio+=elem.getMonto();
    }

 /*   cout<<"\nTotal Activos:\t\t "<<totalAct
       <<"\nTotal Pasivos:\t\t "<<totalPasivo
      <<"\nTotal Patrimonio:\t"<<totalPatrimonio
     <<"\nComprobante: "<<totalAct<<" = "<<totalPasivo+totalPatrimonio;
*/
    /********************************************************/
    fichero<<"\nTotal Activos:\t\t "<<totalAct
       <<"\nTotal Pasivos:\t\t "<<totalPasivo
      <<"\nTotal Patrimonio:\t"<<totalPatrimonio
     <<"\nComprobante: \n Activos = Pasivos + Patrimonios \n "<<totalAct<<" = "<<totalPasivo+totalPatrimonio;
    /********************************************************/
    fichero.close();
}

const vector<Patrimonio> &Balance::getPatrimonios() const
{
    return Patrimonios;
}

void Balance::setPatrimonios(const vector<Patrimonio> &newPatrimonios)
{
    Patrimonios = newPatrimonios;
}

const vector<Tipo> &Balance::getLista_tipos() const
{
    return Lista_tipos;
}

void Balance::setLista_tipos(const vector<Tipo> &newLista_tipos)
{
    Lista_tipos = newLista_tipos;
}

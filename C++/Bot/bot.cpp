#include "bot.h"
#include <fstream>
Bot::Bot()
{

}

Bot::~Bot()
{

}

Nodo *Bot::getRaiz() const
{
    return raiz;
}

void Bot::setRaiz(Nodo *newRaiz)
{
    raiz = newRaiz;
}

const map<string, string> &Bot::getMapa_respuesta() const
{
    return Mapa_respuesta;
}

void Bot::setMapa_respuesta(const map<string, string> &newMapa_respuesta)
{
    Mapa_respuesta = newMapa_respuesta;
}

void Bot::addMapa(const string &clave, const string &valor)
{
    this->Mapa_respuesta.insert(pair<string,string>(clave,valor));
}

Decision Bot::tomaDeciosiones(const vector<string> &input)
{
    Decision inicio;
    this->getRaiz()->tomaDecisiones(this->getRaiz(),&inicio,input);
    return inicio;
}

void Bot::printLista() const
{
    ofstream fichero;fichero.open("Arbol.txt",ios::out | ios::trunc);
    cout<<"\nRaiz";
    fichero<<"\nRaiz";
    this->getRaiz()->printNodo(this->getRaiz(),this->getMapa_respuesta(),fichero);
    fichero.close();
}

bool Bot::buildLista(Nodo *newNodo, int rama, int padre)
{
    if(this->getRaiz()==NULL||newNodo->getId_nodo()==0){
        this->setRaiz(newNodo);
        return true;
    }else{
        if(rama==1){
            if(this->getRaiz()->getNodoIzq()==NULL && padre==0){
                this->getRaiz()->setNodoIzq(newNodo);
                return true;
            }else{
                return AddRama(this->getRaiz()->getNodoIzq(),newNodo,padre);
            }
        }else{
            if(this->getRaiz()->getNodoDrc()==NULL && padre==0){
                this->getRaiz()->setNodoDrc(newNodo);
                return true;
            }else{
                return AddRama(this->getRaiz()->getNodoDrc(),newNodo,padre);
            }
        }
    }
    return false;
}

bool Bot::AddRama(Nodo *list, Nodo *newNodo, int padre){
   Nodo *aux=list;
   if(padre == -1){
       while (aux->getNodoIzq()!=NULL) {
           aux=aux->getNodoIzq();
       }
       aux->setNodoIzq(newNodo);
       return true;
   }else{
       while(aux->getId_nodo()!=padre){
           aux=aux->getNodoIzq();
       }
       if(aux->getId_nodo()==padre){
           if(aux->getNodoDrc()==NULL){
               aux->setNodoDrc(newNodo);
           }else{
               while(aux->getNodoDrc()!=NULL){
                   aux=aux->getNodoDrc();
               }
               aux->setNodoDrc(newNodo);
               return true;
           }
           return true;
       }
   }
   return false;
}

#include "nodo.h"
#include "structs.h"

Nodo::Nodo(const vector<string> &palabras, const string &index_respuesta, int id_nodo)
{
    this->palabras=palabras;
    this->index_respuesta = index_respuesta;
    this->id_nodo=id_nodo;
    this->nodoDrc=NULL;
    this->nodoIzq=NULL;
}

Nodo::Nodo()
{

}

Nodo::~Nodo()
{

}

const vector<string> &Nodo::getPalabras() const
{
    return palabras;
}

void Nodo::setPalabras(const vector<string> &newPalabras)
{
    palabras = newPalabras;
}

Nodo *Nodo::getNodoIzq() const
{
    return nodoIzq;
}

void Nodo::setNodoIzq(Nodo *newNodoIzq)
{
    nodoIzq = newNodoIzq;
}

Nodo *Nodo::getNodoDrc() const
{
    return nodoDrc;
}

void Nodo::setNodoDrc(Nodo *newNodoDrc)
{
    nodoDrc = newNodoDrc;
}


const string &Nodo::getIndex_respuesta() const
{
    return index_respuesta;
}

void Nodo::setIndex_respuesta(const string &newIndex_respuesta)
{
    index_respuesta = newIndex_respuesta;
}

int Nodo::getId_nodo() const
{
    return id_nodo;
}

void Nodo::setId_nodo(int newId_nodo)
{
    id_nodo = newId_nodo;
}

void Nodo::printNodo(Nodo *nodo, const map<string, string> &mapa, ofstream &fichero) const
{
    cout<<"\n--------------------------------";
    cout<<"\nNodo "<<nodo->id_nodo
       <<"\nPalabras: ";
    for(const string &elem:nodo->getPalabras()){
        cout<<"-"<<elem;
    }
    cout<<"\nClave: "<<nodo->getIndex_respuesta()
       <<"\nRespuesta: "<<mapa.at(nodo->getIndex_respuesta());
    cout<<"\n--------------------------------";

    /******************************/
    fichero<<"\n--------------------------------";
    fichero<<"\nNodo "<<nodo->id_nodo;
    fichero  <<"\nPalabras: ";
    for(const string &elem:nodo->getPalabras()){
        fichero<<"-"<<elem;
    }
    fichero <<"\nClave: "<<nodo->getIndex_respuesta();
    fichero <<"\nRespuesta: "<<mapa.at(nodo->getIndex_respuesta());
    fichero<<"\n--------------------------------";
    /******************************/
    if(nodo->getNodoDrc()!=NULL){
        if(nodo->getId_nodo()==0){
            cout<<"\nLista Decrecha";
            fichero<<"\nLista Decrecha";
        }else{
            cout<<"\nRama";
            fichero<<"\nRama";
        }
        printNodo(nodo->getNodoDrc(),mapa,fichero);
    }
    if(nodo->getNodoIzq()!=NULL){
        if(nodo->getId_nodo()==0){
            cout<<"\nLista Izquierda";
            fichero<<"\nLista Izquierda";
        }else{
            cout<<"\nSiguiente nodo Principal";
            fichero<<"\nSiguiente nodo Principal";
        }
        printNodo(nodo->getNodoIzq(),mapa,fichero);
    }
}

void Nodo::tomaDecisiones(Nodo *nodoEstudio, Decision *decision, const vector<string> &texto)
{
    //cout<<"\nEstoy en nodo: "<<nodoEstudio->getId_nodo();
    vector<string> l={},r={};
    if(nodoEstudio->getId_nodo()==0){//es la raiz
        if(nodoEstudio->getNodoIzq()!=NULL){
            l= this->coincide(nodoEstudio->getNodoIzq()->getPalabras(),texto);
         //   cout<<"\nPalabras Coincidentes L: "<<l.size();
        }
        if(nodoEstudio->getNodoDrc()!=NULL){
            r= this->coincide(nodoEstudio->getNodoDrc()->getPalabras(),texto);
          //  cout<<"\nPalabras Coincidentes R: "<<r.size();
        }

        if(l.size()==0 && r.size()==0){
            decision->decision_Menu=nodoEstudio->getId_nodo();
            decision->mapa_decisiones.insert(pair<string,string>("Saludo",nodoEstudio->getIndex_respuesta()));
        }else if (l.size()>r.size()){
            decision->decision_Menu=nodoEstudio->getNodoIzq()->getId_nodo();
            decision->mapa_decisiones.insert(pair<string,string>(nodoEstudio->getNodoIzq()->getIndex_respuesta(),l.at(0)));
             tomaDecisiones(nodoEstudio->getNodoIzq(),decision,texto);
        }else{
            decision->decision_Menu=nodoEstudio->getNodoDrc()->getId_nodo();
            decision->mapa_decisiones.insert(pair<string,string>(nodoEstudio->getNodoDrc()->getIndex_respuesta(),r.at(0)));
             tomaDecisiones(nodoEstudio->getNodoDrc(),decision,texto);
        }
    }else{//soy un nodo limitante
        if(nodoEstudio->getNodoIzq()!=NULL){
            l= this->coincide(nodoEstudio->getNodoIzq()->getPalabras(),texto);
            if(l.size()>0){
                decision->decision_Menu=nodoEstudio->getNodoIzq()->getId_nodo();
               decision->mapa_decisiones.insert(pair<string,string>(nodoEstudio->getNodoIzq()->getIndex_respuesta(),l.at(0)));
                 tomaDecisiones(nodoEstudio->getNodoIzq(),decision,texto);
            }
        }

        if(nodoEstudio->getNodoDrc()!=NULL){
            Nodo *aux=nodoEstudio;
            while(aux->getNodoDrc()!=NULL){
                aux=aux->getNodoDrc();
                r= this->coincide(aux->getPalabras(),texto);
                if(r.size()>0){
                    decision->decision_Menu=aux->getId_nodo();
                    decision->mapa_decisiones.insert(pair<string,string>(aux->getIndex_respuesta(),r.at(0)));
                }
            }
        }
    }
}

vector<string> Nodo::coincide(const vector<string> &palabras, const vector<string> &texto)
{
    vector<string> coincidencias={},palabras_=palabras,texto_=texto;
    std::sort(palabras_.begin(), palabras_.end());
    std::sort(texto_.begin(), texto_.end());

    // Buscamos las palabras coincidentes
    std::set_intersection(palabras_.begin(), palabras_.end(), texto_.begin(), texto_.end(), std::back_inserter(coincidencias));

    return coincidencias;
}

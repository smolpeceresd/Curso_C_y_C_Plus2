#ifndef FUNCIONAMIENTO_H
#define FUNCIONAMIENTO_H

#include <iostream>
#include <fstream>
#include <string>
#include <balance.h>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <patrimonio.h>

using namespace std;

vector<string> trocea(const string &linea, char caracter){

    std::vector<std::string> subcadenas;
    std::stringstream ss(linea);
    std::string subcadena;

    while (std::getline(ss,subcadena,caracter)) {
        subcadenas.push_back(subcadena);
    }
    /*
    for(int i=0;i<subcadenas.size();i++){
        cout<<"\n"<<i<<". "<<subcadenas.at(i);
    }
    */
    return subcadenas;
}




void leerFichero(const string &nombreFich, Balance *balance){
    string linea;
    vector<string> param;
    ifstream fich;fich.open(nombreFich,ios::in);

    if(fich.fail()){
        cout<<"\nEl archivo: "<<nombreFich<<" no se pha podido abrir";
    }else{
        while(!fich.eof()){
            getline(fich,linea);
            //cout<<"\n"<<linea;
            if(linea.find("/")==-1){
                param=trocea(linea,'\t');
                balance->addLista(Tipo(param.at(0),stoi(param.at(1)),param.at(2)));
            }
        }
    }
    // balance->printLista();
    fich.close();
}

int inLista(const string &nombre, const vector<Tipo> &vec){
    vector<Tipo> copy=vec;
    std::vector<Tipo>::iterator it = std::find_if(copy.begin(), copy.end(), [nombre](const Tipo& elemento) {
        return elemento.getNombre() == nombre;
    });
    if (it != copy.end()) {
        int posicion = static_cast<int>(std::distance(copy.begin(), it));
        return posicion;
    }else{
        return -1;
    }
}

void addActPas(const string &nombreFich,Balance *balance){
    string linea;
    vector<string> param;
    ifstream fich;fich.open(nombreFich,ios::in);
    if(fich.fail()){
        cout<<"\nEl archivo: "<<nombreFich<<" no se ha podido abrir.";
    }else{
        while(!fich.eof()){
            getline(fich,linea);
            //  cout<<"\n"<<linea;
            if(linea.find("#")==-1){
                param=trocea(linea,'\t');
                int item = inLista(param.at(0),balance->getLista_tipos());
                if(item != -1){
                    if(balance->getLista_tipos().at(item).getCategoria()=="Activo"){
                        balance->addActivo(Activo(param.at(0),stoi(param.at(1)),param.at(2),balance->getLista_tipos().at(item).getCirculante_no_circulante()));
                    }else if(balance->getLista_tipos().at(item).getCategoria()=="Pasivo"){
                        balance->addPasivo(Pasivo(param.at(0),stoi(param.at(1)),param.at(2),balance->getLista_tipos().at(item).getCirculante_no_circulante()));
                    }else{
                        balance->addPatrimonio(Patrimonio(param.at(0),stoi(param.at(1)),param.at(2),balance->getLista_tipos().at(item).getCirculante_no_circulante()));
                    }

                }else{
                    throw string{"\n Hay un problema con los datos de entrada, revisalos.\n No se encuentra "+param.at(0)};
                }
            }
        }
    }
}

#endif // FUNCIONAMIENTO_H

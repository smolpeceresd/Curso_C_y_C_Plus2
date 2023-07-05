#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <fstream>
#include <string>
#include <bot.h>
#include <vector>
#include <sstream>
#include <vehiculo.h>

using namespace std;

vector<string> trocea(const string &linea, char caracter){

    std::vector<std::string> subcadenas;
    std::stringstream ss(linea);
    std::string subcadena;

    while (std::getline(ss,subcadena,caracter)) {
        subcadenas.push_back(subcadena);
    }

    /*for(int i=0;i<subcadenas.size();i++){
        cout<<"\n"<<i<<". "<<subcadenas.at(i);
    }*/
    return subcadenas;
}



void leerFichero(const string &nombreFich, Bot *bot){
    string linea;
    vector<string> param;
    ifstream fich;fich.open(nombreFich,ios::in);

    if(fich.fail()){
        cout<<"\nEl archivo: "<<nombreFich<<" no se pha podido abrir";
    }else{
        while(!fich.eof()){
            getline(fich,linea);
            if(linea.find("/")==-1){
                param=trocea(linea,'\t');
                if(param.at(0)!="Despedida"&&param.at(0)!="Default"&&param.at(0)!="Inicio"){
                    Nodo *newNodo = new Nodo(trocea(param.at(1),' '),param.at(0),stoi(param.at(3)));
                    bot->buildLista(newNodo,stoi(param.at(5)),stoi(param.at(4)));
                }
                bot->addMapa(param.at(0),param.at(2));
            }
        }
       // bot->printLista();
    }
    fich.close();
}
#endif // FUNCIONES_H

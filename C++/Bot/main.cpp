#include <iostream>
#include <fstream>
#include <string>
#include <bot.h>
#include <basico.h>
using namespace std;



void getParametros(const string &fichero, Bot *bot ){
    ifstream archivo(fichero,ios::in);
    if(archivo.fail()){
        throw string{"Se ha introducido mal la ruta"};
    }
    string linea;
    int index;
    while(!archivo.eof()){
        getline(archivo,linea);
        if((index=static_cast<int>(linea.find("->")))!=-1){ // es un básico

            bot->addBasico(Basico(linea.substr(0,index-1),linea.substr(index+3,linea.size()-1)));
        }else{

            int index_p=linea.find("\t"),
                    index_frase=linea.find("\t",index_p+1),
                    digit=stoi(linea.substr(linea.find_first_of("0123456789"),index));
                    cout<<"\nindex1: "<<index_p<<"\nindex2: "<<index_frase<<"\nFrase: "<<linea;
            bot->addaccion(Accion(digit,linea.substr(index_p+1,(index_frase-index_p)),linea.substr(index_frase+1,((linea.size()-1)-index_frase))));
        }
    }
    archivo.close();
}



int main()

{
    cout << "Hello World!" << endl;
    Bot *bot= new Bot();
    getParametros("Inteligencia.txt",bot);
    bot->printBasicos();
    cout<<"\nACCIONES: "<<bot->getAcciones().size();
    bot->printAcciones();

    string texto;

    cout<<"\n\n";
    return 0;
}

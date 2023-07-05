#include <iostream>
#include <funciones.h>
#include <structs.h>
#include <bot.h>
#include <concesionario.h>
#include <vehiculo.h>
using namespace std;

int main()
{
    Bot *mybot =new Bot();
    leerFichero("Mapa_de_decision.txt",mybot);
    Vehiculo a("Leon","Cupra",0,30000),b("Ibiza","Seat",3,28000),c("Octavia","Skoda",2354,26000),d("Focus","Ford",20000,12000);
    vector<Vehiculo> v={a,b,c,d};
    Concesionario concesionario("C\\Madrid,28000",{"Cupra","Seat","Ford","Skoda"},v);
    string orden;
    int contador=3;


    cout<<"\n"<<mybot->getMapa_respuesta().at("Inicio");
    while(contador>0 && orden !="Adios"){
        cout<<"\nInput: ";
        std::getline(std::cin, orden);
        if(orden != "Adios"){


            vector<string> orden_ = trocea(orden,' ');

            Decision decision_ = mybot->tomaDeciosiones(orden_);

            /*  cout<<"\nDecision Menu : "<<decision_.decision_Menu;
        for (const auto& par : decision_.mapa_decisiones) {
            const std::string& clave = par.first;
            const std::string& valor = par.second;
            std::cout << "\nClave: " << clave << ", Valor: " << valor << std::endl;
        }*/
            switch (decision_.decision_Menu) {
            case 0:case 1:case 2:case 6:
                //  system("cls");
                contador--;
                if(contador!=0){
                    cout<<mybot->getMapa_respuesta().at(decision_.mapa_decisiones.rbegin()->first);
                }
                break;
            case 3:
                concesionario.printVehiculo(decision_.mapa_decisiones.at("Marca"),decision_.mapa_decisiones.at("Modelo"),3);
                break;
            case 4:
                concesionario.printVehiculo(decision_.mapa_decisiones.at("Marca"),decision_.mapa_decisiones.at("Modelo"),4);
                break;
            case 5:
                concesionario.printVehiculo(decision_.mapa_decisiones.at("Marca"),decision_.mapa_decisiones.at("Modelo"),5);
                break;
            case 7:
                concesionario.printMarcas();
                break;
            case 8:
                cout<<"\n El concesionario se encuentra en: "<<concesionario.getUbicacion();
                break;
            }
        }
    }
    if(orden == "Adios"){
        cout<<"\n"<<mybot->getMapa_respuesta().at("Despedida")<<"\n\n";
    }else{
        cout<<mybot->getMapa_respuesta().at("Default")<<"\n\n";
    }
    return 0;
}

#include <iostream>
#include <balance.h>
#include <funcionamiento.h>
using namespace std;

int main()
{
    Balance *balance = new Balance();
    try {
        /**
         * Paso 0 Genero el funcionamiento de "Balance"
         */
        leerFichero("ListaTipos.txt",balance);
        /**
         * Paso 1 Genero los Act Pass y Patrimonios
         */
        addActPas("Datos.txt",balance);

        /**
         * Paso 2 Calculo el Balance
         */

        balance->calculaBalance();

        cout<<"\n Se ha Generado un archivo Balance.txt con los calculos del balance.";

    } catch (string error) {
        cout<<"\nError: "<<error;
    }
    delete balance;
    cout<<"\n\n\n";
}

#include <iostream>
#include <balancesheet.h>
using namespace std;

int main()
{

    Balancesheet myBalance("myBalace");
    Balancesheet AnotherBalanceSheet(100,"AnotherBalanceSheet");

    cout<<"\n\tObjeto myBalance\n"
    <<"\nValor total obtenido forzosamente "<<myBalance.iValorTotal
    <<"\nValor total obtenido por el get "<<myBalance.getIValorTotal()
    <<"\nValor protegido obtenido por el get "<<myBalance.getValorProtegido()
    <<"\nValor privado obtenido por el get "<<myBalance.getValorPrivado()
    <<"\n\n\tObjeto AnotherBalancesheet\n"
    <<"\nValor total obtenido forzosamente "<<AnotherBalanceSheet.iValorTotal
    <<"\nValor total obtenido por el get "<<AnotherBalanceSheet.getIValorTotal()
    <<"\nValor protegido obtenido por el get "<<AnotherBalanceSheet.getValorProtegido()
    <<"\nValor privado obtenido por el get "<<AnotherBalanceSheet.getValorPrivado();


    return 0;
}

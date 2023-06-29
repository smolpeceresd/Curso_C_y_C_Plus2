#include <string>


using namespace std;

#ifndef BALANCESHEET_H
#define BALANCESHEET_H


class Balancesheet
{
public:
    Balancesheet(string name);
    Balancesheet(int iBalance,string name);
    virtual ~Balancesheet();
    int iValorTotal;
    int getIValorTotal();
    int getValorProtegido();
    int getValorPrivado();
    string getName();

protected:
    int valorProtegido=1111;
private:
    string whoami;
    int valorPrivado=222;

};

#endif // BALANCESHEET_H

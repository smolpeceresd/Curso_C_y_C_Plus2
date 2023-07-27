#include <iostream>
#include <CArchivo.h>
using namespace std;

int main()
{
    cout << "\nHello World!" << endl;
    CArchivo<string> a("texto.txt");
    cout<<a;
    return 0;
}

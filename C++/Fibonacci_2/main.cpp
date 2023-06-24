#include <iostream>
#include <array>
#include <vector>
#include <set>
using namespace std;


vector<int> Fibonacci(const vector<int> &numeros,int n0 ,int n1, int sucesion){
    vector<int> numeros_=numeros;
    numeros_.push_back(n0+n1);
    if(sucesion==20){
        return numeros_;
    }else{
        return Fibonacci(numeros_,n1,(n0+n1),sucesion+1);
    }
}



/*******************************************/

bool inFibonacci(int n0, int n1, int busco){
    int resultado= n0+n1;

    if(busco == 0 || busco ==1 ){
        return true;
    }else if(resultado>busco){
        return false;
    }else if (resultado==busco){
        return true;
    }else{
        return inFibonacci(n1,resultado,busco);
    }
}

set<int> Pertenecen(const array<int,40> &numeros){
    set<int> pertenecen{};
    for(int i=0; i<numeros.size();i++){
        if(inFibonacci(0,1,numeros.at(i))==true){
            pertenecen.insert(numeros.at(i));
        }
    }
    return pertenecen;
}



int main()
{
    array<int,40> numeros; numeros.fill(0);
    for(int i =0 ; i < numeros.size();i++){
        numeros.at(i)=rand()%100;
    }

    /* Mostrar números por pantalla*/
    cout<<"\nNumeros a estudiar\n";
    for(int i =0 ; i < numeros.size();i++){
        if((i!= 0) && ((i+1)%10==0)){
            cout<<"\n";
        }
        cout<<" | "<<i+1<<". "<<numeros.at(i)<<" | ";

    }

    /* Fibonacci */

    vector<int> fibonacci= Fibonacci({},0,1,1);

    cout<<"\nNumeros Fibonacci\n";
    for(int i =0 ; i < fibonacci.size();i++){
        if((i!= 0) && ((i+1)%10==0)){
            cout<<"\n";
        }
        cout<<" | "<<i+1<<". "<<fibonacci.at(i)<<" | ";
    }
    cout<<"\nNumeros Pertenecientes a Fibonacci\n";

    set<int> pertenecen = Pertenecen(numeros);
    /*
    for(set<int>::iterator i=pertenecen.begin();i!=pertenecen.end();i++){
        cout<<" | "<<*i<<" | ";
    }
    */
    for(const int &elem:pertenecen){
        cout<<" | "<<elem<<" | ";
    }


    cout<<"\n\n";
    return 0;
}

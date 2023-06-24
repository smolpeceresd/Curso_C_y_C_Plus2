#include <iostream>
#include <vector>
#include <string>
using namespace std;


float calculadora(const vector<int> &index_operadores,const string &operacion,int index,float resultado){
    string n1;
    if(index == 0 ){
        n1=operacion.substr(0,(index_operadores.at(0)-0));
        string n2;
        float n1_{stof(n1)}; /*Convertir a float */
        if(index==index_operadores.size()-1){
            n2=operacion.substr(index_operadores.at(index)+1,((operacion.size()-1)-index_operadores.at(index)));
            float n2_{stof(n2)};
            switch (operacion.at(index_operadores.at(index))) {
            case '+':
                return n1_+n2_;
                break;
            case '-':
                return n1_-n2_;
                break;
            case '*':
                return n1_*n2_;
                break;
            case '/':
                return n1_/n2_;
                break;
            default:
                break;
            }
            return 0.0;
        }else{
            n2=operacion.substr(index_operadores.at(0)+1,(index_operadores.at(1)-(index_operadores.at(0)+1)));
            float n2_{stof(n2)};
            switch (operacion.at(index_operadores.at(index))) {
            case '+':
                return calculadora(index_operadores,operacion,index+1,n1_+n2_);
                break;
            case '-':
                return calculadora(index_operadores,operacion,index+1,n1_-n2_);
                break;
            case '*':
                return calculadora(index_operadores,operacion,index+1,n1_*n2_);
                break;
            case '/':
                return calculadora(index_operadores,operacion,index+1,n1_/n2_);
                break;
            default:
                break;
            }
            return 0.0;
        }
    }else if (index==index_operadores.size()-1){
        n1=operacion.substr(index_operadores.at(index)+1,((operacion.size()-1)-index_operadores.at(index)));
        float n1_{stof(n1)};
        switch (operacion.at(index_operadores.at(index))) {
        case '+':
            return resultado+n1_;
            break;
        case '-':
            return resultado-n1_;
            break;
        case '*':
            return resultado*n1_;
            break;
        case '/':
            return resultado/n1_;
            break;
        }

    }else{
        n1=operacion.substr(index_operadores.at(index)+1,(index_operadores.at(index+1)-index_operadores.at(index)+1));
        float n1_{stof(n1)};
        switch (operacion.at(index_operadores.at(index))) {
        case '+':
            return calculadora(index_operadores,operacion,index+1,resultado+n1_);
            break;
        case '-':
            return calculadora(index_operadores,operacion,index+1,resultado-n1_);
            break;
        case '*':
            return calculadora(index_operadores,operacion,index+1,resultado*n1_);
            break;
        case '/':
            return calculadora(index_operadores,operacion,index+1,resultado/n1_);
            break;
        }
    }
    return 0.0;
};



int main()
{
    string operacion={"2+5+8*9/4"};
    vector<int> index_operadores={};

    for(int i=0 ; i < operacion.size();i++){
        if(operacion.at(i)=='+' || operacion.at(i)=='-' || operacion.at(i)=='*' || operacion.at(i)=='/'){
            index_operadores.push_back(i);
        }
    }
    /*
    for(const int &elem: index_operadores){
        cout<<"\nindex "<<elem;
    }

    cout<<"\n\n";

    */
    if(index_operadores.size()==0){
        cout<<"\n Operacion : "<<operacion <<"\n Resultado: "<<operacion;
    }else{
        float cuenta= calculadora(index_operadores,operacion,0,0.0);
        cout<<"\n Operacion : "<<operacion <<"\n Resultado: "<<cuenta;
    }
    cout<<"\n\nFIN";
    return 0;
}

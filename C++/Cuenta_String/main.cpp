#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


struct Palabra{
    string palabra;
    int repeticiones;
};

struct Letra{
    char letra;
    int repeticiones;
};


void Print(const vector<Palabra> &palabras){
    cout<<"\n\t\n-------- Palabras --------\n\n";

    for (int i = 0; i < palabras.size(); ++i) {
        cout<<"\n------------------------------------------";
        cout<<"\nPalabra: "<<palabras.at(i).palabra;
        cout<<"\nRepeticiones: "<<palabras.at(i).repeticiones;
        cout<<"\n------------------------------------------";
    }
}

void PrintL(const vector<Letra> &letras){
    cout<<"\n\t\n-------- Letras --------\n\n";

    for (int i = 0; i < letras.size(); ++i) {
        cout<<"\n------------------------------------------";
        cout<<"\nLetra: "<<letras.at(i).letra;
        cout<<"\nRepeticiones: "<<letras.at(i).repeticiones;
        cout<<"\n------------------------------------------";
    }
}

int Repeticiones(const string &palabra,char letra,int index){
    int repeticion= static_cast<int>(palabra.find(letra,index));
    if(repeticion == -1){
        return 0;
    }else{

        return 1 + Repeticiones(palabra,letra,repeticion+1);
    }
}

void Letras(const vector<Palabra> &palabras){
    vector<Letra> letras;
    for (char letra ='A'; letra<='Z'; letra++){
        int repeticiones{0};
        for(int i=0;i<palabras.size();i++){
            string palabra=palabras.at(i).palabra;
            std::transform(palabra.begin(), palabra.end(), palabra.begin(), ::toupper);
            repeticiones+=Repeticiones(palabra,letra,0);
        }
        if(repeticiones!=0){
            Letra newLetra{
                letra,
                        repeticiones
            };
            letras.push_back(newLetra);
        }
    }

    if(!letras.empty()){
        PrintL(letras);
    }else{
        cout<<"\n No has introducido ninguna palabra.";
    }

}

int search(const vector<Palabra> &palabras, string palabra){
    for(int i=0;i<palabras.size();i++) {
        if(palabras.at(i).palabra == palabra){
            return i;
        };
    }
    return -1;
}



int main()
{
    vector<Palabra> palabras;
    string palabra;
    do{
        cout<<"Dime la palabra: ";cin>>palabra;
        if(palabra != "Salir"){
            int index = search(palabras,palabra );
            if(index != -1){
                palabras.at(index).repeticiones+=1;
            }else{
                Palabra newPalabra{
                    palabra,
                            1
                };
                palabras.push_back(newPalabra);
            }
        }

    }while(palabra!="Salir");
    system("cls");
    Print(palabras);
    Letras(palabras);
    cout<<"\n";



    return 0;
}

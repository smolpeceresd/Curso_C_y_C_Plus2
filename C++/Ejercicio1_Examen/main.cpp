#include <iostream>
#include <vector>

using namespace std;

bool inVector(const vector<char> &letras, char letra){
    for(const char &letra_:letras){
        if(letra==letra_){
            return true;
        }
    }
    return false;
}

vector<char> getChars(const string &text1,const string &text2){
    vector<char> letras={};
    vector<char> rep={};
    for(int i=0;i<text2.size();i++){
        char letra=text2.at(i);
        if(inVector(letras,letra)==false){
            letras.push_back(letra);
        }
    }

    for(const char &letra_vector:letras){
        for(const char &letra_texto:text1){
            if(letra_vector==letra_texto){
                rep.push_back(letra_vector);
                break;
            }
        }
    }
    return rep;
};

int main()
{
    string texto1{"un perro come"},texto2{"una  puerta"};;
    vector<char> repeticiones= getChars(texto1,texto2);
    cout<<"\n\n Las letras coincidentes son: ";
    for(const char &letra:repeticiones){
        cout<<"\n * "<<letra;
    }
    cout<<"\n\n";
    return 0;
}

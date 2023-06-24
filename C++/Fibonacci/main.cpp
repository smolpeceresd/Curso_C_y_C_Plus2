#include <iostream>

using namespace std;

int Fibonnaci(int n0 ,int n1, int sucesion){
    if(sucesion==1){
        return n0+n1;
    }else{
        cout<<n0+n1<<" ";
        return Fibonnaci(n1,(n0+n1),sucesion-1);
    }
}

int main()
{
    bool continuar;

    do{
        int num_sucesion;
        do{
            cout<<"\nCuantos numeros deaseas ver de la sucesion: ";
            cin>> num_sucesion;
            if(num_sucesion<0){
                cout<<"\nDebe ser un número positvo y mayor o igual que 1";
            }else if( num_sucesion == 1 || num_sucesion<=0){
                cout<<"\nSucesion: 0";
            }else if(num_sucesion == 2 ){
                cout<<"\nSucesion: 0 1";
            }
            else{
                cout<<"Secusion: 0 1 "<<Fibonnaci(0,1,num_sucesion-2);
            }
        }while(num_sucesion<1);
        cout<<"\nDeseas volver a hacer el ejercicio? 1 Si 0 No\n Eleccion: ";cin>>continuar;
        system("cls");
    }while(continuar==1);
    return 0;
}

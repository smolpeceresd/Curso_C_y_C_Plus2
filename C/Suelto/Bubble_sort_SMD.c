#include <stdio.h>


void sort(int a[6],int index_0,int index_1,int iteraciones){
    if(index_0<=iteraciones){
        if(a[index_0]>a[index_1]){
            int aux=a[index_1];
            a[index_1]=a[index_0];
            a[index_0]=aux;
            sort(a,0,1,iteraciones);
        }else{
            sort(a,index_0+1,index_1+1,iteraciones);
        }
    }

}

int main()
{
    int numeros[6]={8,5,4,2,1,7};
    int longitud = sizeof(numeros) / sizeof(numeros[0]);
    sort(numeros,0,1,longitud-1);
    for(int i=0 ; i <6;i++){
        printf(" %i",numeros[i]);
    }

    return 0;
}

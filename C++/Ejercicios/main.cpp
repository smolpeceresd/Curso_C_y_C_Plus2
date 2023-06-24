#include <iostream>
#include <vector>

using namespace std;


struct Estudiante{
    string nombre;
    string email;
    int curso;
};

struct Carrera{
    string nombre;
    vector<Estudiante> estudiantes;
};

Carrera Informatica{
    "Informatica",
    {}
};
Carrera Qumica{
    "Quimica",
    {}
};
Carrera Fisica{
    "Fisica",
    {}
};
Carrera Matematicas{
    "Matematicas",
    {}
};
vector<Carrera> universidad{
    Informatica,Qumica,Fisica,Matematicas
};

int Menu(){
    int opcion;
    do{
        cout<<"\n\nQue quieres hacer "
           <<"\n1. Anadir Estudiante."
          <<"\n2. Borrar Estudiante."
         <<"\n3. Listar estudiantes por carrera."
        <<"\n4. Listar todos los estudiantes."
        <<"\n5. Salir."
        <<"\nOpcion: ";
        cin>>opcion;
        if(opcion<1 || opcion >5){
            cout<<"\n Opcion no valida\n";
        }
    }while(opcion<1 || opcion >5);
    return opcion;
};



void Listar_Carrera(int carrera){
    cout<<"\n\nCarrera -> "<< universidad.at(carrera).nombre;
    if(universidad.at(carrera).estudiantes.empty()){
        cout<<"\n No hay estudiantes para listar en la carrera de "<<universidad.at(carrera).nombre<<".";
    }else{
        for(int j=0; j< universidad.at(carrera).estudiantes.size();j++){
            cout<<"\n\n-"<<(j+1)<<"-------------------------------------------------------------------";
            cout<<"\nNombre del estudiante: "<<universidad.at(carrera).estudiantes.at(j).nombre;
            cout<<"\nCurso del estudiante: "<<universidad.at(carrera).estudiantes.at(j).curso;
            cout<<"\nemail del estudiante: "<<universidad.at(carrera).estudiantes.at(j).email;
            cout<<"\n---------------------------------------------------------------------";
        }
    }
}
void Listar_Carrera(){
    int carrera;
    do{
        system("cls");
        cout<<"\nQue carrera quieres listar:";
        for(int i = 0 ;i< universidad.size();i++){
            cout<<"\n"<<(i+1)<<". "<<universidad.at(i).nombre;
        }
        cout<<"\nOpcion:";
        cin>>carrera;
        if(carrera<1 && carrera> universidad.size()){
            cout<<"\nPor favor escoge una carrera correcta.";
        }
    }while(carrera<1 || carrera> universidad.size());
    system("cls");
    Listar_Carrera(carrera-1);
}
void Listar_todos(){
    system("cls");
    for(int i=0; i < universidad.size();i++){
        Listar_Carrera(i);
    }
}
void Borrar_estudiante(int carrera,int estudiante){
    universidad.at(carrera).estudiantes.erase(universidad.at(carrera).estudiantes.begin()+estudiante);
    cout<<"\nLista Actualizada\n";
    Listar_Carrera(carrera);
}

void Borrar_estudiante(){
    int carrera ;
    do{
        cout<<"\nEn que carrera esta el estudiante?";
        for(int i = 0 ;i< universidad.size();i++){
            cout<<"\n"<<(i+1)<<". "<<universidad.at(i).nombre;
        }
        cout<<"\nCarrera: ";
        cin>>carrera;
        if(carrera <1 || carrera>universidad.size()){
            system("cls");
            cout<<"\nIntroduce una opción valida.";
        }
    }while(carrera <1 || carrera>universidad.size());
    system("cls");

    if(!universidad.at(carrera-1).estudiantes.empty()){
        int estudiante;
        do{
            cout<<"\n\nCual es es el estudiante?";
            Listar_Carrera(carrera-1);
            cout<<"\nEstudiante: ";
            cin>>estudiante;
            if(estudiante<1 || estudiante> universidad.at(carrera-1).estudiantes.size()){
                system("cls");
                cout<<"\nEscoge bien el estudiante por favor.";
            }
        }while(estudiante<1 || estudiante> universidad.at(carrera-1).estudiantes.size());
        Borrar_estudiante(carrera-1,estudiante-1);
    }else{
        cout<<"No se pueden borrar estudiantes de la carrera de"<<universidad.at(carrera-1).nombre<<".";
    }
}

void add_estudiante(){
    system("cls");
    string nombre,email;
    int curso;
    cout <<"\nDime el nombre del estudiante: ";
    cin>>nombre;
    cout <<"\nDime el email del estudiante: ";
    cin>>email;
    cout <<"\nEn que curso se encuentra el estudiante: ";
    cin>>curso;

    Estudiante newEstudiante{
        nombre,
                email,
                curso
    };
    int carrera{0};
    do{
        cout<<"\nEn que carrera se matricula: ";
        for(int i =0; i < universidad.size();i++){
            cout<<"\n"<<(i+1)<<" "<<universidad.at(i).nombre;
        }
        cout<<"\nEleccion: ";cin>>carrera;

        if(carrera<1 || carrera>universidad.size()){
            cout<<"\nEleccion no valida.";
        }
    }while(carrera<1 || carrera>universidad.size());
    universidad.at(carrera-1).estudiantes.push_back(newEstudiante);
    system("cls");
}
int main()
{
    int opcion;
    do{
        opcion=Menu();
        switch (opcion) {
        case 1:
            add_estudiante();
            break;
        case 2:
            Borrar_estudiante();
            break;
        case 3:
            Listar_Carrera();
            break;
        case 4:
            Listar_todos();
            break;
        case 5:
            cout<<"\nSaliendo de la aplicacion.";
            break;
        default:
            system("cls");
            cout<<"\nIntroduce una opcion valida.";
            break;
        }
    }while(opcion!=5);

}



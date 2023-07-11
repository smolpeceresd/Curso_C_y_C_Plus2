#include "activo.h"

Activo::Activo(const string &descripcion_, double monto_, const string  &fecha_, bool circulante_no_circulante)
    : Parametros(descripcion_, monto_, fecha_), Circulante(circulante_no_circulante)
{

}

Activo::~Activo()
{

}

void Activo::print(ofstream &fichero) const
{
   /* cout<<"\n-----------------------------------------";
    cout<<"\nDescripcion: "<<this->getDescripcion()
       <<"\nMonto: "<<this->getMonto()
      <<"\nFecha Vencimiento "<<this->getFecha();
    if(this->getCirculante_no_circulante()==1){
        cout<<"\nCategoria: Circulante";
    }else{
        cout<<"\nCategoria: No Circulante";
    }
    cout<<"\n-----------------------------------------";*/
    /*********************************************************/

    fichero<<"\n-----------------------------------------";
    fichero<<"\nDescripcion: "<<this->getDescripcion()
       <<"\nMonto: "<<this->getMonto()
      <<"\nFecha Vencimiento "<<this->getFecha();
    if(this->getCirculante_no_circulante()==1){
        fichero<<"\nCategoria: Circulante";
    }else{
        fichero<<"\nCategoria: No Circulante";
    }
    fichero<<"\n-----------------------------------------";
}

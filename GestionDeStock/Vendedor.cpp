#include "Vendedor.h"

using namespace std;


    // Constructor de Vendedor
Vendedor::Vendedor(int IdVendedor, std::string nombre,  std::string apellido,  std::string direccion, int dni)

{
    setIdVendedor(idVendedor);
    setNombre(nombre);
    setApellido(apellido);
    setDireccion(direccion);
    setDni(dni);
}

    Vendedor:: Vendedor(): Persona(){idVendedor=0;}

   // Métodos get y set para idCliente
    int Vendedor:: getIdVendedor(){return idVendedor; }
    void Vendedor:: setIdVendedor(int _idVendedor){idVendedor=_idVendedor;}

bool Vendedor::getEliminado(){
   return _eliminado;
}

void Vendedor::setEliminado(bool eliminado){
   _eliminado = eliminado;}

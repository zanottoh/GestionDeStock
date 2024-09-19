#include "Vendedor.h"
#include "ArchivoVendedores.h"
using namespace std;


    // Constructor de Cliente
Vendedor::Vendedor(int IdVendedor, const std::string& nombre, const std::string& apellido, const std::string& direccion, int dni)
    : Persona(nombre, apellido, direccion, dni) // Llamada al constructor de Persona
{
    setIdVendedor(idVendedor);   // Inicializaci�n de idVendedor usando el m�todo set

}

    Vendedor:: Vendedor(): Persona(){idVendedor=0;};

   // M�todos get y set para idCliente
    int Vendedor:: getIdVendedor()const{ return idVendedor; }
    void Vendedor:: setIdVendedor(int idVendedor){idVendedor=idVendedor;}



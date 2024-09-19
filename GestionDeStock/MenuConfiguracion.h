#pragma once
#include "ArchivoVenta.h"
#include "GestorDeProducto.h"
#include "ArchivoVendedor.h"
#include "ArchivoCliente.h"



class MenuConfiguracion{

public:
    void menu();

private:


    void copiaSeguridadVentas();
    void copiaSeguridadProducto();
    void copiaSeguridadCliente();
    void copiaSeguridadVendedor();
    void restaurarArchivoProducto();
    void restaurarArchivoVentas();
    void restaurarArchivoCliente();
    void restaurarArchivoVendedor();

   ArchivoVenta _archivoVenta;
   ArchivoProducto _archivoProducto;
   ArchivoVendedor _archivoVendedor;
   ArchivoCliente _archivoCliente;

};

#pragma once
#include "Vendedor.h"

class ArchivoVendedor {
public:

    bool guardar(Vendedor reg);
    bool guardar(int index, Vendedor reg);

    void leerTodos(Vendedor reg[], int cantidad);
    int buscarByID(int id);
    Vendedor leerVendedor(int index);
    int getCantidadRegistros();
    int getNuevoID();
    bool copiaSeguridad(const char *nombreCopia);

private:

    Vendedor reg;

};

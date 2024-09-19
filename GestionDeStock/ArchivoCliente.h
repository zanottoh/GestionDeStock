#pragma once
#include "Cliente.h"

class ArchivoCliente {
public:
    bool guardar(Cliente registro);
    bool guardar(int index, Cliente registro);

    void leerTodos(Cliente registros[], int cantidad);
    int buscarByID(int id);
    Cliente leerCliente(int index);
    int getCantidadRegistros();
    int getNuevoID();
    int buscarByDni(int dni);
    bool copiaSeguridad(const char *nombreCopia);
private:

    Cliente reg;

};

#pragma once
#include "Venta.h"

class ArchivoVenta {
public:
    bool guardar(Venta registro);
    bool guardar(int index, Venta registro);

    void leerTodos(Venta registros[], int cantidad);
    int buscarByID(int id);
    Venta leerVenta(int index);
    int getCantidadRegistros();
    int getNuevoID();
    bool copiaSeguridad(const char *nombreCopia);
private:

    Venta reg;

};





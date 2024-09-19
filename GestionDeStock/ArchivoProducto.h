#pragma once
#include "Producto.h"

class ArchivoProducto {
public:
   bool guardar(Producto registro);
   bool guardar(int index, Producto registro);
   Producto leer(int index);

   void leerTodos(Producto registros[], int cantidad);

   /// devuelva el indice
   int buscarByID(int id);



   int getCantidadRegistros();//te trae el total de registros

   int getNuevoID();//crea un nuevo ID automatico

   bool copiaSeguridad(const char *nombreCopia);
private:

};

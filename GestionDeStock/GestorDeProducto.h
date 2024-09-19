#pragma once
#include "Producto.h"
#include "ArchivoProducto.h"

class GestorDeProducto {
public:
   void menu();
   void listarProductos(); /// 1) Cantidad de Registros. 2) Muestra la cantidad de productos con ArchivoProductos.leer
   void agregarProducto(); /// Llama a la funcion Guardar, de Archivo Producto. Envia el parametro de Crear Producto.
   void mostrarProducto(Producto &registro); /// Muestra Producto usando los "Gets"
   void volverCargarProducto(Producto &registro); /// modifica solicitando parametro &producto
   void modificarProducto(); /// Usa la funcion BuscarID
   void eliminarProducto();
private:

   Producto crearProducto();/// Carga de datos de Producto, retorna  un objeto de tipo "Producto".


   ArchivoProducto _archivoProducto;


};

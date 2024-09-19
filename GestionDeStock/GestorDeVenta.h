#pragma once
#include "ArchivoVenta.h"
#include "GestorDeProducto.h"
#include "ArchivoVendedor.h"
#include "ArchivoCliente.h"



class GestorDeVenta {
public:
   void menuVentas();
private:
    ///INTERACCIÓN CON VENTA
   void agregarVenta(); /// Llama a la funcion Guardar, de Archivo Venta. Envia el parametro de Crear venta.
   void listarVentas(); /// muestra los registros de archivoVentas.
   Venta crearVenta();/// Carga de datos de Venta, retorna  un objeto de tipo "Venta".
   void mostrarVenta(Venta &registro); /// Muestra Venta usando los "Gets"
   float calcularMontoVenta(int id, int cantidadVenta);/// calcula monto de la venta * cantidad * 1.30 (margen de ganancia 30%
   std:: string obtenerMarca(int id); /// te da la marca del producto según el id producto
   std:: string obtenerModelo(int id); ///te da el modelo del producto según el id producto
   void TotalFacturado(); /// Te da el total facturado a la fecha.

   ///INTERACCIÓN CON PRODUCTO
   void listarProductos(int categoria);/// lista productos según categoria indicada
   void descontarStock(int id, int cantidad); /// descuenta stock según el id que le coloques y va a restar la cantidad indicada-
   int obtenerStock(int id); /// Te trae el stock que tiene según ID.
   void mostrarProducto(Producto &registro); /// Muestra el producto
   bool verificarProductosEnCategoria(int categoria); /// Te devuelve true si encuentra productos de la categoria ingresada en producto.dat


   ///INTERACCIÓN CON VENDEDOR
   bool buscarVendedor(int idVendedor); /// TE DEVUELVE TRUE SIE ENCUENTRA EL IdVendedor en vendedores.dat
   void listarVendedores(); ///Lista los vendedores disponibles.
   void eliminarVendedor();
   bool buscarVendedorEliminado(int idVendedor); /// TE DEVUELVE TRUE SI EL VENDEDOR ESTA ELIMINADO


    ///INTERACCIÓN CON CLIENTE
   Cliente ingresarNuevoCliente(int d);/// TE DA MENU PARA INGRESAR Y SETEAR LOS DATOS DE UN NUEVO CLIENTE
   void agregarCliente(int dni);/// guarda en archivoCliente al cliente.
   void mostrarVendedores(Vendedor &reg);///muestra los vendedores
   Vendedor crearVendedor();///crea los vendedores.
   void agregarVendedor();///guarda el vendedor creado en agregarVendedor
   bool validarClienteDni(int dni); /// TE DEVUELVE TRUE SI ENCUENTRA EL DNI EN CLIENTE.DAT


///DECLARACION DE LOS DISTINTOS ARCHIVOS EN GESTOR DE VENTA:
   ArchivoVenta _archivoVenta;
   ArchivoProducto _archivoProducto;
   ArchivoVendedor _archivoVendedor;
   ArchivoCliente _archivoCliente;


};

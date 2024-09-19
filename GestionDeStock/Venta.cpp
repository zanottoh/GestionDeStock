#include <cstring>
#include "Venta.h"
#include "Producto.h"





// Constructor por defecto
Venta::Venta() {
    Fecha fecha(0,0,0);
    _idVenta = 0;
   _precioVenta = 0.0f;
   _idCliente = 0;
    _idVendedor = 0;
    _marca;
   _modelo;
}




// Constructor parametrizado
Venta::Venta(const Fecha& fecha, int idVenta, float precioVenta, int idCliente, int idVendedor, std::string marca, std::string modelo){

    setFecha(fecha);
    setIdVenta(idVenta);
    setPrecioVenta(precioVenta);
    setIdCliente(idCliente);
    setIdVendedor(idVendedor);
    setMarca(marca);
    setModelo(modelo);
}

// Getters y Setters

// FECHA FECHA

int Venta::getIdVenta() {
    return _idVenta;
}

void Venta::setIdVenta(int idVenta) {
    _idVenta = idVenta;
}

float Venta::getPrecioVenta() {
    return _precioVenta;
}

void Venta::setPrecioVenta(float precioVenta) {

    _precioVenta=precioVenta;
}

int Venta::getIdCliente() {
    return _idCliente;
}

void Venta::setIdCliente(int idCliente) {
    _idCliente = idCliente;
}

int Venta::getIdVendedor() {
    return _idVendedor;
}

void Venta::setIdVendedor(int idVendedor) {
    _idVendedor = idVendedor;
}

void Venta::setFecha(const Fecha& fecha) {
    _fecha = fecha;
}

 Fecha Venta::getFecha() const {
    return _fecha;
}


std::string Venta::getMarca() {
   return _marca;
}

void Venta::setMarca(std::string marca) {
   strcpy(_marca,marca.c_str());
}

std::string Venta::getModelo() {
   return _modelo;
}

void Venta::setModelo(std::string modelo) {
    strcpy(_modelo,modelo.c_str());
}







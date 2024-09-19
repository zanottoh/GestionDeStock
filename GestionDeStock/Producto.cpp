#include <cstring>
#include "Producto.h"

Producto::Producto() {
   _categoria = 0;
   _id = 0;
   strcpy(_marca, "");
   strcpy(_modelo, "");
   _precio = 0.0f;
   _stock = 0;
   _eliminado = 0;
}

Producto::Producto(int categoria, int id, std::string marca, std::string modelo, float precio, int stock, bool eliminado) {
   setCategoria(categoria);
   setID(id);
   setMarca(marca);
   setModelo(modelo);
   setPrecio(precio);
   setStock(stock);
   setEliminado(eliminado);
}

int  Producto::getCategoria() {
   return _categoria;
}

void Producto::setCategoria(int categoria) {
   _categoria = categoria;
}

int Producto::getID() {
   return _id;
}

void Producto::setID(int id) {
   _id = id;
}

std::string Producto::getMarca() {
   return _marca;
}

void Producto::setMarca(std::string marca) {
   strcpy(_marca,marca.c_str());
}

std::string Producto::getModelo() {
   return _modelo;
}

void Producto::setModelo(std::string modelo) {
    strcpy(_modelo,modelo.c_str());
}

float Producto::getPrecio() {
   return _precio;
}

void Producto::setPrecio(float precio) {
   _precio = precio;
}

int Producto::getStock() {
   return _stock;
}

void Producto::setStock(int stock) {
   _stock = stock;
}


bool Producto::getEliminado(){
   return _eliminado;
}

void Producto::setEliminado(bool eliminado){
   _eliminado = eliminado;
}

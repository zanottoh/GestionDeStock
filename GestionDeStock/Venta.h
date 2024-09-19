#pragma once
#include <cstring>
#include "Fecha.h"
#include "Producto.h"
#include "ArchivoProducto.h"


class Venta {

private:

    Producto obj;
    Fecha _fecha; // Tiene que venir de la clase FECHA.
    int _idVenta;
    float _precioVenta; /// MODIFICAR
    int _idCliente;
    int _idVendedor;
    char _marca[20];
    char _modelo[20];




public:

    Venta();
    Venta(const Fecha& fecha, int idVenta, float precioVenta, int idCliente, int idVendedor, std::string marca, std::string modelo);

    // FECHA fecha

    int getIdVenta();
    void setIdVenta(int idVenta);

    float getPrecioVenta();
    void setPrecioVenta(float precioVenta);

    int getIdCliente();
    void setIdCliente(int idCliente);

    int getIdVendedor();
    void setIdVendedor(int idVendedor);

    void setFecha(const Fecha& fecha);
    Fecha getFecha() const;

    std::string getMarca();
    void setMarca(std::string _marca);

    std::string getModelo();
    void setModelo(std::string _modelo);

};





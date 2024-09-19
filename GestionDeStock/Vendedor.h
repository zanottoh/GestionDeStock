#pragma once
#include "Persona.h"

class Vendedor : public Persona {
private:
    int idVendedor;
    bool _eliminado;


public:
   Vendedor(int idVendedor, std::string nombre, std::string apellido, std::string direccion, int dni);
   Vendedor();

    int getIdVendedor();
    void setIdVendedor(int _idVendedor);
    void vendedoresDisponibles();
    void mostrarVendedores(Vendedor &reg);
    bool getEliminado();
    void setEliminado(bool eliminado);



};

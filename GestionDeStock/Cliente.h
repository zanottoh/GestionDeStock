#pragma once
#include "Persona.h"
#include <iostream>


class Cliente : public Persona {
private:
    int idCliente;
    char mail[30];
    char telefono [30];

public:
   Cliente(int idCliente, std::string nombre, std::string apellido, std::string direccion, int dni, std::string mail, std::string telefono);
   Cliente();


    int getIdCliente();
    void setIdCliente(int _idCliente);

    std::string getMail();
    void setMail(std::string mail);

    std::string getTelefono();
    void setTelefono(std::string telefono);

};

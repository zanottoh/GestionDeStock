#pragma once
#include <iostream>


class Persona {

private:
    char nombre [30];
    char apellido[30];
    int dni;
    char direccion [30];


public:

      Persona(std::string nombre, std::string apellido, std::string direccion, int dni);
      Persona();

        std::string getNombre() ;
    void setNombre(std::string _nombre);

    std::string getApellido();
    void setApellido(std::string _apellido);

    int getDni();
    void setDni(int dni);

    std::string getDireccion();
    void setDireccion(std::string _direccion);

    /* std::string toString() const {
        return std::to_string(_nombre) + " " + std::to_string(_apellido);
    }*/ ///funcion para anexar nombre y apellido.







};

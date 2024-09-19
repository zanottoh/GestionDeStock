#include <cstring>
#include "Persona.h"



        ///constructor Persona
      Persona:: Persona(std::string nombre, std::string apellido, std::string direccion, int dni){
       setNombre(nombre);
       setApellido(apellido);
       setDni(dni);
       setDireccion(direccion);


      }

   Persona:: Persona(){

    strcpy(nombre, "");
    strcpy(apellido, "");
    strcpy(direccion, "");

    dni= 0;



   }


    // Métodos get y set para nombre
std::string Persona::getNombre()  { return nombre; }
void Persona::setNombre(std::string _nombre) {
   strcpy(nombre,_nombre.c_str());}

// Métodos get y set para apellido
std::string Persona::getApellido()  { return apellido; }

void Persona::setApellido(std::string _apellido) {
   strcpy(apellido,_apellido.c_str());
}

// Métodos get y set para dni
int Persona::getDni()  { return dni; }
void Persona::setDni(int _dni) { dni = _dni; }


// Métodos get y set para direccion
std::string Persona::getDireccion()  { return direccion; }

void Persona::setDireccion(std::string _direccion) {
   strcpy(direccion,_direccion.c_str());}



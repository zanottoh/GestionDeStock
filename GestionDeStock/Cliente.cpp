///#pragma once
#include "Cliente.h"
#include <cstring>
using namespace std;

// Constructor de Cliente
Cliente::Cliente(int idCliente, std::string nombre, std::string apellido,std::string direccion, int dni,std::string mail, std::string telefono)

{
    setIdCliente(idCliente);
    setNombre(nombre);
    setApellido(apellido);
    setDni(dni);
    setDireccion(direccion);
    setMail(mail);
    setTelefono(telefono);
}

Cliente:: Cliente():Persona(){
    idCliente=0;
    strcpy(mail, "");
    strcpy(telefono, "");
}



   // Métodos get y set para idCliente
    int Cliente:: getIdCliente(){ return idCliente; }
    void Cliente:: setIdCliente(int _idCliente){idCliente=_idCliente;}

    // Métodos get y set para mail
    std::string Cliente:: getMail() { return mail; }
   void Cliente::setMail(std::string _mail) {
   strcpy(mail,_mail.c_str());}

    // Métodos get y set para telefono
    std::string Cliente::getTelefono()  { return telefono; }
    void Cliente::setTelefono(std::string _telefono) {
   strcpy(telefono,_telefono.c_str());}


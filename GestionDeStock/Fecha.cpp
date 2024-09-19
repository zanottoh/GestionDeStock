#include <iostream>
#include <ctime>
#include <string>
#include "Fecha.h"


    // Constructor por defecto que inicializa con la fecha actual
    Fecha::Fecha() {
        time_t t = time(nullptr);
        struct tm* f = localtime(&t);
        _dia = f->tm_mday;
        _mes = f->tm_mon + 1;
        _anio = f->tm_year + 1900;
    }

    // Constructor que permite establecer una fecha específica
   Fecha:: Fecha(int dia, int mes, int anio) {
        _dia = dia;
        _mes = mes;
        _anio = anio;
    }

    // Métodos get
    int Fecha:: getDia() const {
        return _dia;
    }

    int Fecha:: getMes() const {
        return _mes;
    }

    int Fecha:: getAnio() const {
        return _anio;
    }

    // Métodos set
    void Fecha:: setDia(int dia) {
        _dia = dia;
    }

    void Fecha:: setMes(int mes) {
        _mes = mes;
    }

    void  Fecha::setAnio(int anio) {
        _anio = anio;
    }

    // Método para obtener la fecha en formato cadena
    std::string Fecha:: toString() const {
        return std::to_string(_dia) + "/" + std::to_string(_mes) + "/" + std::to_string(_anio);
    }

       // Método para obtener la fecha como cadena (alias para toString)
    std::string Fecha:: getFecha() const {
        return toString();
    }



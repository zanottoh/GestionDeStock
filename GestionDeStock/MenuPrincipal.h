#pragma once
#include "GestorDeProducto.h"
#include "GestorDeVenta.h"
#include "MenuConfiguracion.h"

class MenuPrincipal{
public:
    void menu();
private:
    GestorDeProducto _uno;
    GestorDeVenta _dos;
    MenuConfiguracion _tres;



};

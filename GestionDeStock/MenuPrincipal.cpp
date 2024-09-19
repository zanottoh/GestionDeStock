#include <iostream>
#include "MenuPrincipal.h"

using namespace std;


void MenuPrincipal::menu()
{
    int option;
    while(true){
        system("cls");
    ///"R" raw string literal: se trata como una cadena literal. Se usa R"(...)"
    cout << R"(
     _______________________
    |                       |
    |    MENU PRINCIPAL     |
    |_______________________|
    |_______________________|
    |                       |
    |  INGRESE UNA OPCION   |
    |_______________________|
    |                       |
    | 1. PRODUCTOS          |
    | 2. VENTAS             |
    | 3. CONFIGURACION      |
    | 0. SALIR              |
    |_______________________|

      OPCION: )";cin>>option;




        /*)
        cout << "------ MENU PRINCIPAL ------- " << endl;
        cout << "1- PRODUCTOS " << endl;
        cout << "2- VENTAS" << endl;
        cout << "3- CONFIGURACION" << endl;
        cout << "-----------------------------" << endl;
        cout << "0- SALIR" << endl;
        cout << "Opcion: "<< endl;
        cin >> option;
        */
        switch(option){
        case 1:
              _uno.menu();
            break;
        case 2:
            _dos.menuVentas();
            break;
        case 3:
           _tres.menu();
            break;
        case 0:return;
            break;
        default:cout<<"      OPCION INCORRECTA "<<endl;
            break;
        }
        system("pause");
        system("cls");
    }


}

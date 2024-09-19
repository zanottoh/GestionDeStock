#include <iostream>
#include "ArchivoVenta.h"
#include "ArchivoProducto.h"
#include "MenuConfiguracion.h"
using namespace std;



void MenuConfiguracion:: menu(){


    int opc;
    while(true){
        system("cls");

        cout << R"(
     _____________________________________________
    |                                             |
    |             MENU CONFIGURACION              |
    |_____________________________________________|
    |_____________________________________________|
    |                                             |
    |  INGRESE UNA OPCION                         |
    |_____________________________________________|
    |                                             |
    | 1. COPIA DE SEGURIDAD ARCHIVO PRODUCTO      |
    | 2. COPIA DE SEGURIDAD ARCHIVO VENTAS        |
    | 3. COPIA DE SEGURIDAD ARCHIVO CLIENTE       |
    | 4. COPIA DE SEGURIDAD ARCHIVO VENDEDOR      |
    | 5. RESTAURAR ARCHIVO PRODUCTO               |
    | 6. RESTAURAR ARCHIVO VENTA                  |
    | 7. RESTAURAR ARCHIVO CLIENTE                |
    | 8. RESTAURAR ARCHIVO VENDEDOR               |
    | 0. VOLVER ATRAS                             |
    |_____________________________________________|

      OPCION: )";cin>>opc;


        /*
        cout<<"MENU CONFIGURACION"<<endl;
        cout<<"-----------------"<<endl;
        cout<<"1) COPIA DE SEGURIDAD ARCHIVO PRODUCTO"<<endl;
        cout<<"2) COPIA DE SEGURIDAD ARCHIVO VENTA"<<endl;
        cout<<"3) COPIA DE SEGURIDAD ARCHIVO CLIENTE"<<endl;
        cout<<"4) COPIA DE SEGURIDAD ARCHIVO VENDEDOR"<<endl;
        cout<<"5) RESTAURAR ARCHIVO PRODUCTO"<<endl;
        cout<<"6) RESTAURAR ARCHIVO VENTA"<<endl;
        cout<<"7) RESTAURAR ARCHIVO CLIENTE"<<endl;
        cout<<"8) RESTAURAR ARCHIVO VENDEDOR"<<endl;

        cout<<"--------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"OPCION: "<<endl;
        */

        system("cls");
        switch(opc){
            case 1: copiaSeguridadProducto();
                break;
            case 2: copiaSeguridadVentas();
                    copiaSeguridadProducto();
                break;
            case 3: copiaSeguridadCliente();
                break;
            case 4:
                    copiaSeguridadVendedor();

                break;
            case 5: restaurarArchivoProducto();
                break;
            case 6: restaurarArchivoVentas();
                    restaurarArchivoProducto();
                break;
            case 7: restaurarArchivoCliente();
                break;
            case 8: restaurarArchivoVendedor();
                break;
            case 0:return ;
            default:cout<<"OPCION INCORRECTA"<<endl;
                break;
        }
        system("pause");

    }
}



void MenuConfiguracion::copiaSeguridadVentas() {
    FILE *origen = fopen("venta.dat", "rb");
    FILE *destino = fopen("ventaCopiaSeguridad.bak", "wb");

    if (origen == nullptr || destino == nullptr) {
        cout << "ERROR AL ABRIR LOS ARCHIVOS" << endl;
        return;
    }

    Venta reg;
    while (fread(&reg, sizeof(reg), 1, origen) == 1) {
        if (fwrite(&reg, sizeof(reg), 1, destino) != 1) {
            cout << "ERROR AL ESCRIBIR EN EL ARCHIVO DE COPIA" << endl;
            fclose(origen);
            fclose(destino);
            return;
        }
    }

    fclose(origen);
    fclose(destino);

    cout << "COPIA GENERADA EXITOSAMENTE" << endl;
}

void MenuConfiguracion::copiaSeguridadProducto() {
    FILE *origen = fopen("producto.dat", "rb");
    FILE *destino = fopen("productoCopiaSeguridad.bak", "wb");

    if (origen == nullptr || destino == nullptr) {
        cout << "ERROR AL ABRIR LOS ARCHIVOS" << endl;
        return;
    }

    Producto reg;
    while (fread(&reg, sizeof(reg), 1, origen) == 1) {
        if (fwrite(&reg, sizeof(reg), 1, destino) != 1) {
            cout << "ERROR AL ESCRIBIR EN EL ARCHIVO DE COPIA" << endl;
            fclose(origen);
            fclose(destino);
            return;
        }
    }

    fclose(origen);
    fclose(destino);

    cout << "COPIA GENERADA EXITOSAMENTE" << endl;
}


void MenuConfiguracion::copiaSeguridadVendedor() {
    FILE *origen = fopen("vendedor.dat", "rb");
    FILE *destino = fopen("vendedorCopiaSeguridad.bak", "wb");

    if (origen == nullptr || destino == nullptr) {
        cout << "ERROR AL ABRIR LOS ARCHIVOS" << endl;
        return;
    }

    Vendedor reg;
    while (fread(&reg, sizeof(reg), 1, origen) == 1) {
        if (fwrite(&reg, sizeof(reg), 1, destino) != 1) {
            cout << "ERROR AL ESCRIBIR EN EL ARCHIVO DE COPIA" << endl;
            fclose(origen);
            fclose(destino);
            return;
        }
    }

    fclose(origen);
    fclose(destino);

    cout << "COPIA GENERADA EXITOSAMENTE" << endl;
}


void MenuConfiguracion::copiaSeguridadCliente() {
    FILE *origen = fopen("cliente.dat", "rb");
    FILE *destino = fopen("clienteCopiaSeguridad.bak", "wb");

    if (origen == nullptr || destino == nullptr) {
        cout << "ERROR AL ABRIR LOS ARCHIVOS" << endl;
        return;
    }

    Cliente reg;
    while (fread(&reg, sizeof(reg), 1, origen) == 1) {
        if (fwrite(&reg, sizeof(reg), 1, destino) != 1) {
            cout << "ERROR AL ESCRIBIR EN EL ARCHIVO DE COPIA" << endl;
            fclose(origen);
            fclose(destino);
            return;
        }
    }

    fclose(origen);
    fclose(destino);

    cout << "COPIA GENERADA EXITOSAMENTE" << endl;
}

///RENAME, funcion de c++. Renombra el archivo NOMBRE COPIA  al NOMBRE ORIGINAL. Rename devuelve 0 si es ok de lo contrario devuelve -1.

/// REMOVE, funcion de c++. Elimina el archivo si existe. Se neceista para generar la restauracion sin problema.

void MenuConfiguracion:: restaurarArchivoProducto() {
    const char *nombreOriginal = "producto.dat";
    const char *nombreCopia = "productoCopiaSeguridad.bak";

     remove(nombreOriginal);


    if (rename(nombreCopia, nombreOriginal) == 0) {
        cout << "RESTAURACION DEL ARCHIVO EXISTOSA" << endl;
    } else {
        cout << "ERROR AL RESTAURAR EL ARCHIVO" << endl;
    }

}


void MenuConfiguracion:: restaurarArchivoVentas() {
    const char *nombreOriginal = "venta.dat";
    const char *nombreCopia = "ventaCopiaSeguridad.bak";


    remove(nombreOriginal);


    if (rename(nombreCopia, nombreOriginal) == 0) {
        cout << "RESTAURACION DEL ARCHIVO EXISTOSA" << endl;
    } else {
        cout << "ERROR AL RESTAURAR EL ARCHIVO" << endl;
    }
}

void MenuConfiguracion:: restaurarArchivoVendedor() {
    const char *nombreOriginal = "vendedor.dat";
    const char *nombreCopia = "vendedorCopiaSeguridad.bak";


    remove(nombreOriginal);


    if (rename(nombreCopia, nombreOriginal) == 0) {
        cout << "RESTAURACION DEL ARCHIVO EXISTOSA" << endl;
    } else {
        cout << "ERROR AL RESTAURAR EL ARCHIVO" << endl;
    }
}


void MenuConfiguracion:: restaurarArchivoCliente() {
    const char *nombreOriginal = "cliente.dat";
    const char *nombreCopia = "clienteCopiaSeguridad.bak";


    remove(nombreOriginal);


    if (rename(nombreCopia, nombreOriginal) == 0) {
        cout << "RESTAURACION DEL ARCHIVO EXISTOSA" << endl;
    } else {
        cout << "ERROR AL RESTAURAR EL ARCHIVO" << endl;
    }
}



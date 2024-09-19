#include "ArchivoVenta.h"
#include <iostream>
using namespace std;


bool ArchivoVenta::guardar(Venta reg) {
    FILE *pFile = fopen("venta.dat", "ab");
    if (pFile == nullptr) {
        return false;
    }
    bool result = fwrite(&reg, sizeof(Venta), 1, pFile);
    fclose(pFile);
    return result;
}

bool ArchivoVenta::guardar(int index, Venta reg) {
    FILE *pFile = fopen("venta.dat", "rb+");
    if (pFile == nullptr) {
        return false;
    }
    fseek(pFile, sizeof(Venta) * index, SEEK_SET);
    bool result = fwrite(&reg, sizeof(Venta), 1, pFile);
    fclose(pFile);
    return result;
}

int ArchivoVenta::buscarByID(int id) {
    Venta reg;
    int pos = 0;
    FILE *pFile = fopen("venta.dat", "rb");
    if (pFile == nullptr) {
        return -1;
    }
    while (fread(&reg, sizeof(Venta), 1, pFile)) {
        if (reg.getIdVenta() == id) {
            fclose(pFile);
            return pos;
        }
        pos++;
    }
    fclose(pFile);
    return -1;
}

Venta ArchivoVenta::leerVenta(int index) {
    Venta reg;
    FILE *pFile = fopen("venta.dat", "rb");
    if (pFile == nullptr) {
        return reg;
    }
    fseek(pFile, index * sizeof(Venta), SEEK_SET);
    fread(&reg, sizeof(Venta), 1, pFile);
    fclose(pFile);
    return reg;
}

void ArchivoVenta::leerTodos(Venta registros[], int cantidad) {
    FILE *pFile = fopen("venta.dat", "rb");
    if (pFile == nullptr) {
        return;
    }
    fread(registros, sizeof(Venta), cantidad, pFile);
    fclose(pFile);
}

int ArchivoVenta::getCantidadRegistros() {
    FILE *pFile = fopen("venta.dat", "rb");
    if (pFile == nullptr) {
        return 0;
    }
    fseek(pFile, 0, SEEK_END);
    int tam = ftell(pFile) / sizeof(Venta);
    fclose(pFile);
    return tam;
}

int ArchivoVenta::getNuevoID() {
    int cantidad = getCantidadRegistros();
    if (cantidad > 0) {
        return leerVenta(cantidad - 1).getIdVenta() + 1;
    } else {
        return 1;
    }
}


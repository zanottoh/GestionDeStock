#include "ArchivoVendedor.h"


bool ArchivoVendedor::guardar(Vendedor reg) {

    FILE *pFile = fopen("vendedor.dat", "ab");


    if (pFile == nullptr) {
        return false;
    }
    bool result = fwrite(&reg, sizeof(Vendedor), 1, pFile);
    fclose(pFile);
    return result;
}

bool ArchivoVendedor::guardar(int index, Vendedor reg) {
    FILE *pFile = fopen("vendedor.dat", "rb+");
    if (pFile == nullptr) {
        return false;
    }
    fseek(pFile, sizeof(Vendedor) * index, SEEK_SET);
    bool result = fwrite(&reg, sizeof(Vendedor), 1, pFile);
    fclose(pFile);
    return result;
}

int ArchivoVendedor::buscarByID(int id) {
    Vendedor reg;
    int pos = 0;
    FILE *pFile = fopen("vendedor.dat", "rb");
    if (pFile == nullptr) {
        return -1;
    }
    while (fread(&reg, sizeof(Vendedor), 1, pFile)) {
        if (reg.getIdVendedor() == id) {
            fclose(pFile);
            return pos;
        }
        pos++;
    }
    fclose(pFile);
    return -1;
}

Vendedor ArchivoVendedor::leerVendedor(int index) {
    Vendedor reg;
    FILE *pFile = fopen("vendedor.dat", "rb");
    if (pFile == nullptr) {
        return reg;
    }
    fseek(pFile, index * sizeof(Vendedor), SEEK_SET);
    fread(&reg, sizeof(Vendedor), 1, pFile);
    fclose(pFile);
    return reg;
}

void ArchivoVendedor::leerTodos(Vendedor registros[], int cantidad) {
    FILE *pFile = fopen("vendedor.dat", "rb");
    if (pFile == nullptr) {
        return;
    }
    fread(registros, sizeof(Vendedor), cantidad, pFile);
    fclose(pFile);
}

int ArchivoVendedor::getCantidadRegistros() {
    FILE *pFile = fopen("vendedor.dat", "rb");
    if (pFile == nullptr) {
        return 0;
    }
    fseek(pFile, 0, SEEK_END);
    int tam = ftell(pFile) / sizeof(Vendedor);
    fclose(pFile);
    return tam;
}

int ArchivoVendedor::getNuevoID() {
    int cantidad = getCantidadRegistros();
    if (cantidad > 0) {
        return leerVendedor(cantidad - 1).getIdVendedor() + 1;
    } else {
        return 1;
    }
}

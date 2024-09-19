#include "ArchivoCliente.h"



bool ArchivoCliente::guardar(Cliente reg) {
    FILE *pFile = fopen("cliente.dat", "ab");
    if (pFile == nullptr) {
        return false;
    }
    bool result = fwrite(&reg, sizeof(Cliente), 1, pFile);
    fclose(pFile);
    return result;
}

bool ArchivoCliente::guardar(int index, Cliente reg) {
    FILE *pFile = fopen("cliente.dat", "rb+");
    if (pFile == nullptr) {
        return false;
    }
    fseek(pFile, sizeof(Cliente) * index, SEEK_SET);
    bool result = fwrite(&reg, sizeof(Cliente), 1, pFile);
    fclose(pFile);
    return result;
}

int ArchivoCliente::buscarByID(int id) {
    Cliente reg;
    int pos = 0;
    FILE *pFile = fopen("cliente.dat", "rb");
    if (pFile == nullptr) {
        return -1;
    }
    while (fread(&reg, sizeof(Cliente), 1, pFile)) {
        if (reg.getIdCliente() == id) {
            fclose(pFile);
            return pos;
        }
        pos++;
    }
    fclose(pFile);
    return -1;
}



int ArchivoCliente::buscarByDni(int dni) {
    Cliente reg;
    int pos = 0;
    FILE *pFile = fopen("cliente.dat", "rb");
    if (pFile == nullptr) {
        return -1;
    }
    while (fread(&reg, sizeof(Cliente), 1, pFile)) {
        if (reg.getDni() == dni) {
            fclose(pFile);
            return reg.getIdCliente();
        }
        pos++;
    }
    fclose(pFile);
    return -1;
}

Cliente ArchivoCliente::leerCliente(int index) {
    Cliente reg;
    FILE *pFile = fopen("cliente.dat", "rb");
    if (pFile == nullptr) {
        return reg;
    }
    fseek(pFile, index * sizeof(Cliente), SEEK_SET);
    fread(&reg, sizeof(Cliente), 1, pFile);
    fclose(pFile);
    return reg;
}

void ArchivoCliente::leerTodos(Cliente registros[], int cantidad) {
    FILE *pFile = fopen("cliente.dat", "rb");
    if (pFile == nullptr) {
        return;
    }
    fread(registros, sizeof(Cliente), cantidad, pFile);
    fclose(pFile);
}

int ArchivoCliente::getCantidadRegistros() {
    FILE *pFile = fopen("cliente.dat", "rb");
    if (pFile == nullptr) {
        return 0;
    }
    fseek(pFile, 0, SEEK_END);
    int tam = ftell(pFile) / sizeof(Cliente);
    fclose(pFile);
    return tam;
}

int ArchivoCliente::getNuevoID() {
    int cantidad = getCantidadRegistros();
    if (cantidad > 0) {
        return leerCliente(cantidad - 1).getIdCliente() + 1;
    } else {
        return 1;
    }
}



#include "ArchivoProducto.h"




bool ArchivoProducto::guardar(Producto reg){ // GUARDAR REGISTRO NUEVO
   bool result;
   FILE *pFile;

   pFile = fopen("producto.dat", "ab");

   if(pFile == nullptr){

      return false;
   }

   result = fwrite(&reg, sizeof (Producto), 1, pFile);

   fclose(pFile);

   return result;
}

bool ArchivoProducto::guardar(int index, Producto reg){ // ES PARA GUARDAR UNA MODIFICACION DE REGISTRO
   bool result;
   FILE *pFile;

   pFile = fopen("producto.dat", "rb+");

   if(pFile == nullptr){

      return false;
   }

   fseek(pFile, sizeof(Producto) * index, SEEK_SET);

   result = fwrite(&reg, sizeof (Producto), 1, pFile);

   fclose(pFile);

   return result;
}

int ArchivoProducto::buscarByID(int id){ // buscar por ID
    Producto reg;
    int pos = 0;
    FILE * pFile;

    pFile = fopen("producto.dat", "rb");
    if(pFile == nullptr){
        return -1;
    }

    while(fread(&reg, sizeof(Producto), 1, pFile)){
        if(reg.getID() == id){
            fclose(pFile);
            return pos;
        }
        pos++;
    }

    fclose(pFile);
    return -1;
}

Producto ArchivoProducto::leer(int index){ // LEER SEGUN INDICE
   bool result;
   Producto reg;
   FILE *pFile;

   pFile = fopen("producto.dat", "rb");

   if(pFile == nullptr){
      return reg;
   }

   fseek(pFile, index * sizeof (Producto), SEEK_SET);

   fread(&reg, sizeof(Producto), 1, pFile);

   fclose(pFile);

   return reg;
}


void ArchivoProducto::leerTodos(Producto registros[], int cantidad){ // leer todos
   bool result;
   FILE *pFile;

   pFile = fopen("producto.dat", "rb");

   if(pFile == nullptr){
      return;
   }

   fread(registros, sizeof(Producto), cantidad, pFile);

   fclose(pFile);
}



int ArchivoProducto::getCantidadRegistros(){ // sacar cantidad de registros
   FILE *pFile;
   int tam;

   pFile = fopen("producto.dat", "rb");

   if(pFile == nullptr){
      return 0;
   }

   fseek(pFile, 0, SEEK_END);

   tam = ftell(pFile) / sizeof (Producto);

   fclose(pFile);

   return tam;
}

int ArchivoProducto::getNuevoID(){
    int cantidad = getCantidadRegistros();

    if(cantidad>0){
        return leer(cantidad-1).getID()+1;
    }
    else{
        return 1;
    }
}

#include <iostream>
#include "GestorDeProducto.h"
using namespace std;

///REVISAR EDITAR PRODUCTO POR ID. CUANDO SE LISTA NO TE LO TRAE

void GestorDeProducto::menu(){
   int option;
   system("cls");
   do{

    cout << R"(
     _____________________________________________
    |                                             |
    |             MENU PRODUCTOS                  |
    |_____________________________________________|
    |_____________________________________________|
    |                                             |
    |  INGRESE UNA OPCION                         |
    |_____________________________________________|
    |                                             |
    | 1. AGREGAR PRODUCTO                         |
    | 2. LISTAR TODOS LOS PRODUCTOS               |
    | 3. EDITAR PRODUCTO                          |
    | 4. ELIMINAR PRODUCTO                        |
    | 0. SALIR                                    |
    |_____________________________________________|

      OPCION: )";cin>>option;

      /*
      cout << "------ MENU PRODUCTOS ------- " << endl;
      cout << "1- AGREGAR PRODUCTO " << endl;
      cout << "2- LISTAR TODOS LOS PRODUCTOS" << endl;
      cout << "3- EDITAR PRODUCTO" << endl;
      cout << "-----------------------------" << endl;
      cout << "0- SALIR" << endl;
      cout << "Opcion: ";
      cin >> option;
      */

    system("cls");
      switch(option){
      case 1:
         agregarProducto();
         system("pause");
         break;

      case 2:
         listarProductos();
         system("pause");
         break;

      case 3:
        modificarProducto();
        system("pause");
        break;
        case 4:
        eliminarProducto();
        system("pause");
        break;
      }


      system("cls");
   }while(option != 0);
}

void GestorDeProducto::agregarProducto() // ESTE GUARDA Y CREA EN TEORIA, LLAMA A CREAR DENTRO DE GUARDAR
{

    if(_archivoProducto.guardar(crearProducto()))

    {
        cout << "El producto fue guardado con exito!" << endl;
    }
    else
    {
        cout << "No se pudo guardar el producto!" << endl;
    }
}



Producto GestorDeProducto::crearProducto(){ // ESTE SOLO CREA Y ES LLAMADO POR GUARDAR
    int nuevoID = _archivoProducto.getNuevoID(); // AUTOMATICO.
    int categoria; // CLASE.
    string marca;
    string modelo;
    float precio;
    int stock;
    bool eliminado = false;
    Producto nuevoProducto;

            cout << R"(
     _____________________________________________
    |                                             |
    |        INGRESE CATEGORIA DE PRODUCTO        |
    |_____________________________________________|
    |_____________________________________________|
    |                                             |
    |  INGRESE UNA OPCION                         |
    |_____________________________________________|
    |                                             |
    | 1. PROCESADOR                               |
    | 2. PLACA DE VIDEO                           |
    | 3. MOTHERBOARD                              |
    | 4. DISCO                                    |
    | 5. MEMORIA RAM                              |
    | 6. FUENTE                                   |
    |_____________________________________________|

      OPCION: )";cin>>categoria;

    nuevoProducto.setCategoria(categoria);

    nuevoProducto.setID(nuevoID);
    system("cls");


    cout<<"EL ID DE PRODUCTO GENERADO ES: \n"<<nuevoID<<endl;;

    cin.ignore();
    cout <<"MARCA DEL PRODUCTO: \n";
    getline(cin, marca);
    nuevoProducto.setMarca(marca);


    cout <<"MODELO DEL PRODUCTO \n";
    getline(cin, modelo);
    nuevoProducto.setModelo(modelo);

   cout<< "PRECIO DEL PRODUCTO: \n";
   cin >> precio;
   nuevoProducto.setPrecio(precio);

    cout<< "CANTIDAD (STOCK): \n";
   cin >> stock;
   nuevoProducto.setStock(stock);

   nuevoProducto.setEliminado(eliminado);

   return nuevoProducto;
}


void GestorDeProducto::listarProductos(){
    int cantidad = _archivoProducto.getCantidadRegistros();
    Producto *productos;
    ///Validar cantidad de registros
    productos = new Producto[cantidad];

    if(productos == nullptr)
    {
        cout << "No se pudo pedir memoria... " << endl;
        return;
    }

    _archivoProducto.leerTodos(productos, cantidad);

  /*  if (ordenadoPorPrecio){
      ordenarProductosPorPrecio(productos, cantidad);
    }*/

    for(int i=0; i<cantidad; i++)
    {
        if(!productos[i].getEliminado())
        {
            cout << "--------------------------" << endl;
            mostrarProducto(productos[i]);
            cout<<endl;
            cout << "--------------------------" << endl;
        }
    }

    delete [] productos;
}

void GestorDeProducto::mostrarProducto(Producto &reg){
   cout << "Categoria: "<<reg.getCategoria()<< endl;
   cout << "ID: "<<reg.getID()<<endl;
   cout << "Marca: "<<reg.getMarca()<<endl;
   cout << "Modelo: "<<reg.getModelo()<<endl;
   cout << "Precio: "<<reg.getPrecio()<<endl;
   cout << "Stock: "<<reg.getStock()<< endl;
   /*cout << "Estado: "<<reg.getEliminado();*/

}

void GestorDeProducto::modificarProducto(){
    int idProducto, index;
    Producto producto;

    cout << "INGRESE ID DEL PRODUCTO A MODIFICAR \n";
    cin >> idProducto;

    index = _archivoProducto.buscarByID(idProducto);

    if(index != -1)
    {
        producto = _archivoProducto.leer(index);

        mostrarProducto(producto);

        volverCargarProducto(producto);

        if(producto.getStock()>0){

            producto.setEliminado(false);
        }

        if(_archivoProducto.guardar(index, producto))
        {
            cout << "SE HA MODIFICADO CON EXITO" << endl;
        }
        else
        {
            cout << "NO SE PUDO MODIFICAR" << endl;
        }
    }
    else
    {
        cout << "NO SE ENCUENTRA ID DEL PRODUCTO" << endl;
    }
}


void GestorDeProducto::volverCargarProducto(Producto &registro){
    int id; // AUTOMATICO.
    int categoria; // CLASE.
    string marca;
    string modelo;
    float precio;
    int stock;

            cout << R"(
     _____________________________________________
    |                                             |
    |     INGRESE NUEVA CATEGORIA DE PRODUCTO     |
    |_____________________________________________|
    |_____________________________________________|
    |                                             |
    |  INGRESE UNA OPCION                         |
    |_____________________________________________|
    |                                             |
    | 1. PROCESADOR                               |
    | 2. PLACA DE VIDEO                           |
    | 3. MOTHERBOARD                              |
    | 4. DISCO                                    |
    | 5. MEMORIA RAM                              |
    | 6. FUENTE                                   |
    |_____________________________________________|

      OPCION: )";cin>>categoria;
      system("cls");

    cin.ignore();
    cout <<"MARCA DEL PRODUCTO: \n";
    getline(cin, marca);


    cout <<"MODELO DEL PRODUCTO \n";
    getline(cin, modelo);

    cout<< "PRECIO DEL PRODUCTO: \n";
    cin >> precio;

    cout<< "CANTIDAD (STOCK): \n";
    cin >> stock;

 registro.setCategoria(categoria);
 registro.setMarca(marca);
 registro.setModelo(modelo);
 registro.setPrecio(precio);
 registro.setStock(stock);



}


void GestorDeProducto::eliminarProducto(){
    int idProducto, index;
    Producto producto;
    bool eliminar;

    cout << "INGRESE EL ID DEL PRODUCTO A ELIMINAR: "<<endl;
    cin >> idProducto;


    index = _archivoProducto.buscarByID(idProducto);


    if(index != -1)
    {
        producto = _archivoProducto.leer(index);

        mostrarProducto(producto);

        cout <<"¿ESTA SEGURO QUE DESEA ELIMINARLO?"<<endl;
        cout<<" 1 -Si || 0- No: "<<endl;
        cin >> eliminar;

        if(eliminar)
        {
            producto.setEliminado(true);

            if(_archivoProducto.guardar(index, producto))
            {
                cout << "SE ELIMINO EL PRODUCTO CON EXITO" << endl;
            }
            else
            {
                cout << "NO SE PUDO ELIMINAR EL PRODUCTO" << endl;
            }
        }
        else
        {
            cout<<"EL PRODUCTO NO FUE ELIMINADO"<< endl;

        }
    }
    else
    {
        cout << "NO SE ENCUENTRA EL PRODUCTO" << endl;
    }
}








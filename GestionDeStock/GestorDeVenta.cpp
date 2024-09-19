#include <iostream>
#include "GestorDeVenta.h"
#include "GestorDeProducto.h"
#include "Fecha.h"
#include "ArchivoCliente.h"
#include "ArchivoVendedor.h"
#include <iomanip> // libreria que deja los decimales fijos.

using namespace std;


void GestorDeVenta::menuVentas(){
   int option;
   system("cls");
   do{

          cout << R"(
     _____________________________________________
    |                                             |
    |             MENU VENTAS                     |
    |_____________________________________________|
    |_____________________________________________|
    |                                             |
    |  INGRESE UNA OPCION                         |
    |_____________________________________________|
    |                                             |
    | 1. AGREGAR VENTA                            |
    | 2. LISTAR TODAS LAS VENTAS                  |
    | 3. TOTAL DE FACTURACION Y GANANCIAS         |
    | 4. AGREGAR VENDEDORES                       |
    | 5. LISTAR VENDEDORES                        |
    | 6. ELIMINAR VENDEDORES                      |
    | 0. VOLVER ATRAS                             |
    |_____________________________________________|

        OPCION: )";cin>>option;



/*
      cout << "------ MENU VENTAS ------- " << endl<<endl;
      cout << "1- AGREGAR VENTA " << endl;
      cout << "2- LISTAR TODAS LAS VENTAS" << endl;
      cout << "3- TOTAL DE FACTURACION Y GANANCIAS"<<endl;
      cout << "4- AGREGAR VENDEDORES"<< endl;
      cout << "5 - LISTAR VENDEDORES"<<endl;

      cout << "-----------------------------" << endl;
      cout << "0- SALIR" << endl;
      cout << "Opcion: ";
      cin >> option;
*/
   system("cls");
      switch(option){
      case 1:
         agregarVenta();
       system("pause");
         break;

      case 2:
         listarVentas();
        system("pause");
         break;

      case 3:

        TotalFacturado();
        system("pause");
        break;
    case 4:

        agregarVendedor();
        system("pause");
        break;
    case 5:

        listarVendedores();
        system("pause");
        break;
    case 6:

        eliminarVendedor();
        system("pause");
        break;

      }


    system("cls");
   }while(option != 0);

}

void GestorDeVenta::agregarVenta(){ // ESTE GUARDA Y CREA EN TEORIA, LLAMA A CREAR DENTRO DE GUARDAR
    Venta nuevaVenta = crearVenta();

    if (nuevaVenta.getIdVenta() == -1) {
        cout << "NO SE PUDO REGISTRAR LA VENTA" << endl;
        return; // La venta fue cancelada
    }

    if(_archivoVenta.guardar(nuevaVenta))

    {

        cout << "LA VENTA FUE REGISTRADA CON EXITO" << endl;


    }
    else
    {
        cout << "NO SE PUDO REGISTRAR LA VENTA" << endl;
    }
}



Venta GestorDeVenta::crearVenta(){ // ESTE SOLO CREA Y ES LLAMADO POR GUARDAR
    Producto obj;
    string _fecha = Fecha().toString(); // Tiene que venir de la clase FECHA.
    ArchivoCliente _archivoCliente;
    ArchivoVendedor regArchiVend;
    Vendedor regVend;



    int nuevoIDVenta = _archivoVenta.getNuevoID(); // AUTOMATICO.
    Venta nuevaVenta;
    int option;
    float precioVenta;
    int idCliente;
    int idVendedor;
    int categoria;
    int cantidadVenta;
    int idProducto;
    int dni;

bool productoEncontrado = false;

do {
    cout << "Ingrese Categoria de Producto que quiere vender: " << endl;
    cout << endl;
    cout << "(1) Procesador " << endl;
    cout << "(2) Placa de Video " << endl;
    cout << "(3) Motherboard " << endl;
    cout << "(4) Disco " << endl;
    cout << "(5) Memoria RAM " << endl;
    cout << "(6) Fuente  " << endl;
    cin >> categoria;

    // Validar la entrada
    if (categoria < 1 || categoria > 6) {
        cout << "Categoría inválida. Por favor, ingrese un número entre 1 y 6." << endl;
        continue;  // Vuelve al inicio del bucle
    }

    // Llamamos a listarProductos y verificamos si se encontraron productos
    productoEncontrado = verificarProductosEnCategoria(categoria);

    if (!productoEncontrado) {
        cout << "No se encontraron productos en la categoría: " <<categoria<< endl;
        cout << "Por favor, elija otra categoría." << endl << endl;
    }
} while (!productoEncontrado);

  cout<<"Ingrese el ID del producto que quiere vender: "<<endl;
  cin>>idProducto;


   ///cin.ignore();
   cout <<"Ingrese la cantidad que desea vender: "<<endl;
   cin>>cantidadVenta;

 while(cantidadVenta > obtenerStock(idProducto)){

    cout<<"La cantidad solicitada excede el stock! Ingrese una cantidad menor o igual a: "<<obtenerStock(idProducto)<<endl;

    cin>>cantidadVenta;

 }



 precioVenta= calcularMontoVenta(idProducto,cantidadVenta);


    cout <<"Es cliente: 1 - SI || 2 - NO ";
    cin>>option;
      cout<<"Ingrese DNI del cliente: "<<endl;
      cin>>dni;
    system("cls");
   switch(option){

        case 1:


         if(!validarClienteDni(dni)){
            cout<<"El nro de DNI no esta dado de alta"<<endl;
            cout<<"A continuación se procede a la carga de un nuevo cliente: "<<endl;
            agregarCliente(dni);
            idCliente= _archivoCliente.buscarByDni(dni);

         }else{

            idCliente= _archivoCliente.buscarByDni(dni);
            cout<<"ESTE DNI YA ESTA DADO DE ALTA, SU NRO DE CLIENTE ES: "<<idCliente<<endl;

         };

         ///system("pause");
         break;

         case 2:
               if(!validarClienteDni(dni)){

            agregarCliente(dni);
            idCliente= _archivoCliente.buscarByDni(dni);

         }else{

            idCliente= _archivoCliente.buscarByDni(dni);
            cout<<"ESTE DNI YA ESTA DADO DE ALTA, SU NRO DE CLIENTE ES: "<<idCliente<<endl;



         };


            ///system("pause");
            break;

    }


   bool bandera = false;
while(!bandera){
    cout<<"A continuación se listan los vendedores disponibles: "<<endl;
    listarVendedores();
    cout<<"Ingrese el id del vendedor: "<<endl;




    cin >> idVendedor;
    system("cls");

   bool vendedorEncontrado=buscarVendedor(idVendedor);
   bool vendedorEliminado = buscarVendedorEliminado(idVendedor);




    if(vendedorEncontrado && !vendedorEliminado){
       bandera = true;

    }else {



    cout<<"El ID no esta dado de alta o el vendedor esta eliminado, ingrese otro ID de vendedor: "<<endl;

    }
system("cls");

}

   int confirmacion;
    do {
        cout << "¿Desea confirmar la venta?" << endl;
        cout << "1 - Si || 2 - No" << endl;
        cin >> confirmacion;

        if (confirmacion == 2) {
            cout << "Venta cancelada." << endl;
           nuevaVenta.setIdVenta(-1); /// Usar -1 como indicador de venta cancelada
            return nuevaVenta;
        }
    } while (confirmacion != 1);

    /// Hacer los set y descontar el stock después de la confirmación
    string marca = obtenerMarca(idProducto);
    string modelo = obtenerModelo(idProducto);
    nuevaVenta.setMarca(marca);
    nuevaVenta.setModelo(modelo);
    descontarStock(idProducto, cantidadVenta);
    nuevaVenta.setIdCliente(idCliente);
    nuevaVenta.setIdVenta(nuevoIDVenta);
    nuevaVenta.setPrecioVenta(precioVenta);
    nuevaVenta.setIdVendedor(idVendedor);

    cout << "El ID generado de la Venta es: " << nuevoIDVenta << endl<<endl;
    cout<<"La venta se registro en la siguiente fecha: "<<_fecha<<endl;
    nuevaVenta.setFecha(Fecha()); /// Establecer la fecha actual


    return nuevaVenta;
}


void GestorDeVenta::agregarCliente(int dni){ // ESTE GUARDA Y CREA EN TEORIA, LLAMA A CREAR DENTRO DE GUARDAR

    Cliente nuevoCliente = ingresarNuevoCliente(dni);


    if(_archivoCliente.guardar(nuevoCliente))

    {

        cout << "¡El cliente fue registrado con exito!" << endl;


    }
    else
    {
        cout << "¡No se pudo registrar la venta!" << endl;
    }
}


void GestorDeVenta::listarProductos(int categoria){
    int cantidad = _archivoProducto.getCantidadRegistros();
    Producto *productos = new Producto[cantidad];
    if(productos == nullptr)
    {
        cout << "No se pudo pedir memoria... " << endl;
        return;
    }
    _archivoProducto.leerTodos(productos, cantidad);

    bool productoEncontrado = false;

    for(int i = 0; i < cantidad; i++)
    {
        if(!productos[i].getEliminado() && productos[i].getCategoria() == categoria)
        {
            if (!productoEncontrado) {
                cout << "Productos encontrados en la categoría " << categoria << ":" << endl;
                productoEncontrado = true;
            }
            cout << "--------------------------" << endl;
            mostrarProducto(productos[i]);
            cout << endl;
            cout << "--------------------------" << endl;
        }
    }

    if (!productoEncontrado) {
        cout << "No se encontraron productos en la categoría " << categoria << "." << endl;
    }

    delete[] productos;
}



void GestorDeVenta::listarVentas(){// modificar luego para buscar productos por categoria. void GestorDeProducto::listarProductos

    int cantidad = _archivoVenta.getCantidadRegistros();
    Venta *ventas;

    ventas = new Venta[cantidad];

    if(ventas == nullptr)
    {
        cout << "No se pudo pedir memoria... " << endl;
        return;
    }

    _archivoVenta.leerTodos(ventas, cantidad);

  /*  if (ordenadoPorPrecio){
      ordenarProductosPorPrecio(productos, cantidad);
    }*/

    for(int i=0; i<cantidad; i++)
    {

            cout << "--------------------------" << endl;
            mostrarVenta(ventas[i]);
            cout<<endl;
            cout << "--------------------------" << endl;
        }


    delete [] ventas;
}



void GestorDeVenta::TotalFacturado() {
    int cantidad = _archivoVenta.getCantidadRegistros();
    Venta *ventas = new Venta[cantidad];

    if (ventas == nullptr) {
        std::cout << "No se pudo pedir memoria..." << std::endl;
        return;
    }

    _archivoVenta.leerTodos(ventas, cantidad);

    float totalRecaudado = 0.0f;  // Inicializamos el total a 0
    float totalGanancias = 0.0f;  // Inicializamos el total de ganancias a 0

    // Calcular total recaudado y total de ganancias
    for (int i = 0; i < cantidad; ++i) {
        float precioVenta = ventas[i].getPrecioVenta();
        totalRecaudado += precioVenta;
        float gananciaVenta = precioVenta * 0.3f;  // Calculamos el 30% de ganancia
        totalGanancias += gananciaVenta;
    }

    // Mostrar resultados sin notación científica y con precisión de dos decimales
    std::cout << "Total recaudado hasta la fecha: $" << std::fixed << std::setprecision(2) << totalRecaudado << std::endl;
    std::cout << "Total de ganancias hasta la fecha (30% sobre el total recaudado): $" << std::fixed << std::setprecision(2) << totalGanancias << std::endl;

    delete[] ventas;
}



void GestorDeVenta::descontarStock(int id, int cantidad) {
    int pos = _archivoProducto.buscarByID(id);
    if (pos == -1) {
        cout << "Producto no encontrado." << endl;
        return;
    }

    Producto producto;
    FILE *pFile = fopen("producto.dat", "rb");
    if (pFile == nullptr) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }
    fseek(pFile, pos * sizeof(Producto), SEEK_SET);
    fread(&producto, sizeof(Producto), 1, pFile);
    fclose(pFile);

    int nuevoStock = producto.getStock() - cantidad;
    if (nuevoStock < 0) {
        nuevoStock = 0;
    }
    producto.setStock(nuevoStock);

    if (nuevoStock == 0) {
        producto.setEliminado(true); // Cambiar estado a true (1) si el stock es 0
    }

    _archivoProducto.guardar(pos, producto);
}



float GestorDeVenta::calcularMontoVenta(int id, int cantidadVenta) {
    int pos = _archivoProducto.buscarByID(id);
    if (pos == -1) {
        cout << "Producto no encontrado." << endl;
        return 0.0f;
    }

    Producto producto;
    FILE *pFile = fopen("producto.dat", "rb");
    if (pFile == nullptr) {
        cout << "Error al abrir el archivo." << endl;
        return 0.0f;
    }
    fseek(pFile, pos * sizeof(Producto), SEEK_SET);
    fread(&producto, sizeof(Producto), 1, pFile);
    fclose(pFile);

    float precio = producto.getPrecio();
    float montoVenta = (precio * cantidadVenta) * 1.30f;

    return montoVenta;
}


int GestorDeVenta::obtenerStock(int id) {
    int pos = _archivoProducto.buscarByID(id);
    if (pos == -1) {
        cout << "Producto no encontrado." << endl;
        return -1; // Retorna -1 si el producto no se encuentra
    }

    Producto producto;
    FILE *pFile = fopen("producto.dat", "rb");
    if (pFile == nullptr) {
        cout << "Error al abrir el archivo." << endl;
        return -1;
    }
    fseek(pFile, pos * sizeof(Producto), SEEK_SET);
    fread(&producto, sizeof(Producto), 1, pFile);
    fclose(pFile);

    return producto.getStock();
}




string GestorDeVenta::obtenerMarca(int id) {
    int pos = _archivoProducto.buscarByID(id);
    if (pos == -1) {
        cout << "Producto no encontrado." << endl;
        return ""; // Retorna -1 si el producto no se encuentra
    }

    Producto producto;
    FILE *pFile = fopen("producto.dat", "rb");
    if (pFile == nullptr) {
        cout << "Error al abrir el archivo." << endl;
        return "";
    }
    fseek(pFile, pos * sizeof(Producto), SEEK_SET);
    fread(&producto, sizeof(Producto), 1, pFile);
    fclose(pFile);

    return producto.getMarca();
}


string GestorDeVenta::obtenerModelo(int id) {
    int pos = _archivoProducto.buscarByID(id);
    if (pos == -1) {
        cout << "Producto no encontrado." << endl;
        return ""; // Retorna cadena vacia si el producto no se encuentra
    }

    Producto producto;
    FILE *pFile = fopen("producto.dat", "rb");
    if (pFile == nullptr) {
        cout << "Error al abrir el archivo." << endl;
        return "";
    }
    fseek(pFile, pos * sizeof(Producto), SEEK_SET);
    fread(&producto, sizeof(Producto), 1, pFile);
    fclose(pFile);

    return producto.getModelo();
}




void GestorDeVenta::mostrarVenta(Venta &reg){ // quizas haya que referenciar

   cout << "Fecha de la venta: " << reg.getFecha().getFecha() << endl; // Obtener la fecha como cadena
   cout<<"Marca: "<<reg.getMarca()<<endl;
   cout<<"Modelo: "<<reg.getModelo()<<endl;
   cout << "ID de la venta: "<<reg.getIdVenta()<<endl;
   cout << "Numero de vendedor: "<<reg.getIdVendedor()<<endl;
   cout << "Numero de cliente: "<<reg.getIdCliente()<<endl;
   cout << "Precio: "<<reg.getPrecioVenta()<<endl;
}


void GestorDeVenta::mostrarProducto(Producto &reg){ // quizas haya que referenciar
   cout << "Categoria: "<<reg.getCategoria()<< endl;
   cout << "ID: "<<reg.getID()<<endl;
   cout << "Marca: "<<reg.getMarca()<<endl;
   cout << "Modelo: "<<reg.getModelo()<<endl;
   cout << "Precio: "<<reg.getPrecio()<<endl;
   cout << "Stock: "<<reg.getStock()<< endl;
}


bool GestorDeVenta::verificarProductosEnCategoria(int categoria){
    int cantidad = _archivoProducto.getCantidadRegistros();
    Producto *productos = new Producto[cantidad];
    if(productos == nullptr)
    {
        cout << "No se pudo pedir memoria... " << endl;
        return false;
    }
    _archivoProducto.leerTodos(productos, cantidad);

    bool productoEncontrado = false;

    for(int i = 0; i < cantidad; i++)
    {
        if(!productos[i].getEliminado() && productos[i].getCategoria() == categoria)
        {
            productoEncontrado = true;
            break;  // Salimos del bucle tan pronto como encontramos un producto
        }
    }

    delete[] productos;

    if (productoEncontrado) {
        listarProductos(categoria);  // Llamamos a la función original para mostrar los productos
    }

    return productoEncontrado;
}



bool GestorDeVenta::buscarVendedor(int idVendedor){
    int cantidad = _archivoVendedor.getCantidadRegistros();
    Vendedor *vendedor = new Vendedor[idVendedor];
    if(vendedor == nullptr)
    {
        cout << "No se pudo pedir memoria... " << endl;
        return false;
    }
    _archivoVendedor.leerTodos(vendedor, idVendedor);

    bool vendedorEncontrado = false;

    for(int i = 0; i < cantidad; i++)
    {

        if(vendedor[i].getIdVendedor() == idVendedor)
        {
            vendedorEncontrado = true;
            break;  // Salimos del bucle tan pronto como encontramos el vendedor
        }
    }

    delete[] vendedor;



    return vendedorEncontrado;
}



bool GestorDeVenta::buscarVendedorEliminado(int idVendedor){
    int cantidad = _archivoVendedor.getCantidadRegistros();
    Vendedor *vendedor = new Vendedor[cantidad];

    if(vendedor == nullptr) {
        cout << "No se pudo pedir memoria... " << endl;
        return false;
    }

    _archivoVendedor.leerTodos(vendedor, cantidad);

    bool vendedorEliminado = false;

    for(int i = 0; i < cantidad; i++) {
        if(vendedor[i].getIdVendedor() == idVendedor && vendedor[i].getEliminado() == true) {
            vendedorEliminado = true;
            break;  // Salimos del bucle tan pronto como encontramos el vendedor
        }
    }

    delete[] vendedor;

    return vendedorEliminado;
}


bool GestorDeVenta::validarClienteDni(int dni){
    int cantidad = _archivoCliente.getCantidadRegistros();
    Cliente *cliente = new Cliente[dni];
    if(cliente == nullptr)
    {
        cout << "No se pudo pedir memoria... " << endl;
        return false;
    }
    _archivoCliente.leerTodos(cliente, dni);

    bool clienteEncontrado = false;

    for(int i = 0; i < cantidad; i++)
    {
        if(cliente[i].getDni() == dni)
        {
            clienteEncontrado = true;
            break;  // Salimos del bucle tan pronto como encontramos un producto
        }
    }

    delete[] cliente;


    return clienteEncontrado;
}


Cliente GestorDeVenta:: ingresarNuevoCliente(int d){
    Cliente nuevoCliente;
    string nombre;
    string apellido;
    int dni;
    string mail;
    string telefono;
    string direccion;
    int idCliente;

    ArchivoCliente _archivoCliente;



    cin.ignore();
    cout<<"Ingrese nombre del cliente: "<<endl;
    getline(cin, nombre);

    cout<<"Ingrese el apellido del cliente: "<<endl;
    getline(cin, apellido);

    ///cin.ignore();
    dni=d;
    cout<<"El DNI es: "<<dni<<endl;
   // cin>>dni;


    ///cin.ignore();
    cout<<"Ingrese dirección: "<<endl;
    getline(cin, direccion);
    cout<<"Ingrese mail: "<<endl;
    getline(cin, mail);

    cout<<"Ingrese telefono: "<<endl;
    getline(cin, telefono);

    idCliente= _archivoCliente.getNuevoID();

    cout<<"El ID generado para el cliente es: "<<idCliente<<endl;
    nuevoCliente.setNombre(nombre);
    nuevoCliente.setIdCliente(idCliente);
    nuevoCliente.setTelefono(telefono);
    nuevoCliente.setMail(mail);
    nuevoCliente.setDni(dni);
    nuevoCliente.setApellido(apellido);
    nuevoCliente.setDireccion(direccion);
    return nuevoCliente;


}


void GestorDeVenta::listarVendedores(){
    int cantidad = _archivoVendedor.getCantidadRegistros();
    Vendedor *vendedor = new Vendedor[cantidad];

    if(vendedor == nullptr)
    {
        cout << "No se pudo pedir memoria... " << endl;
        return;
    }

    _archivoVendedor.leerTodos(vendedor, cantidad);

  /*  if (ordenadoPorPrecio){
      ordenarProductosPorPrecio(productos, cantidad);
    }*/

    for(int i=0; i<cantidad; i++)
    {
///

            mostrarVendedores(vendedor[i]);




    }

    delete [] vendedor;
}

 void GestorDeVenta:: mostrarVendedores(Vendedor &reg){

        if(!reg.getEliminado()){
        cout<<"Apellido y nombre: "<<reg.getApellido()<<", "<<reg.getNombre()<<"."<<endl;

        cout<<"ID vendedor: "<<reg.getIdVendedor()<<endl;

        cout<<"--------------------------------------"<<endl;
        cout<<endl;
        }
 }

Vendedor  GestorDeVenta:: crearVendedor(){
    Vendedor nuevoVendedor;
    string nombre;
    string apellido;
    int dni;
    string direccion;
    int idVendedor;

    ArchivoVendedor _archivoVendedor;



    cin.ignore();
    cout<<"Ingrese nombre del Vendedor: "<<endl;
    getline(cin, nombre);
    nuevoVendedor.setNombre(nombre);
    cout<<"Ingrese el apellido del Vendedor: "<<endl;
    getline(cin, apellido);
    nuevoVendedor.setApellido(apellido);


    cout<<"Ingrese el DNI: "<<endl;
    cin>>dni;
    nuevoVendedor.setDni(dni);
    cin.ignore();
    cout<<"Ingrese domicilio: "<<endl;
    getline(cin, direccion);
    nuevoVendedor.setDireccion(direccion);

    idVendedor= _archivoVendedor.getNuevoID();
    nuevoVendedor.setIdVendedor(idVendedor);
    cout<<"El ID generado para el vendedor es: "<<idVendedor<<endl;

    return nuevoVendedor;


}




void GestorDeVenta::agregarVendedor(){ // ESTE GUARDA Y CREA EN TEORIA, LLAMA A CREAR DENTRO DE GUARDAR
    Vendedor nuevoVendedor = crearVendedor();
    ArchivoVendedor _archivoVendedor;


    if(_archivoVendedor.guardar(nuevoVendedor))

    {

        cout << "¡El vendedor fue guardado exito!" << endl;


    }
    else
    {
        cout << "¡No se pudo registrar la venta!" << endl;
    }
}


void GestorDeVenta::eliminarVendedor(){
    int idVendedor, index;
    Vendedor vendedor;
    bool eliminar;

    cout << "INGRESE EL ID DEL VENDEDOR A ELIMINAR: "<<endl;
    cin >> idVendedor;


    index = _archivoVendedor.buscarByID(idVendedor);


    if(index != -1)
    {
        vendedor = _archivoVendedor.leerVendedor(index);

        mostrarVendedores(vendedor);

        cout <<"¿ESTA SEGURO QUE DESEA ELIMINARLO?"<<endl;
        cout<<" 1 -Si || 0- No: "<<endl;
        cin >> eliminar;

        if(eliminar)
        {
            vendedor.setEliminado(true);

            if(_archivoVendedor.guardar(index, vendedor))
            {
                cout << "SE ELIMINO EL VENDEDOR CON EXITO" << endl;
            }
            else
            {
                cout << "NO SE PUDO ELIMINAR EL VENDEDOR" << endl;
            }
        }
        else
        {
            cout<<"EL VENDEDOR NO FUE ELIMINADO"<< endl;

        }
    }
    else
    {
        cout << "NO SE ENCUENTRA EL VENDEDOR" << endl;
    }
}

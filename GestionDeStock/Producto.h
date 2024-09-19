#pragma once
#include <string>

class Producto {
    private:
      int _categoria;
      int _id=0;
      char _marca[20];
      char _modelo[20];
      float _precio;
      int _stock;
      bool _eliminado;

   public:
      Producto();
      Producto(int categoria, int id, std::string marca, std::string modelo, float precio, int stock, bool eliminado);

      int getCategoria();
      void setCategoria(int categoria);

      int getID();
      void setID(int id);

      std::string getMarca();
      void setMarca(std::string marca);

      std::string getModelo();
      void setModelo(std::string modelo);

      float getPrecio();
      void setPrecio(float precio);

      int getStock();
      void setStock(int stock);

      bool getEliminado();
      void setEliminado(bool eliminado);

};

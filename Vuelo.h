#include"fechaHora.h"

class Vuelo{
  //Se declaran los atributos: lugar de origen, lugar destino, nombre de aerolinea,
  //fecha de salida, fecha de llegada y número de vuelo
  private:
    std::string origen;
    std::string destino;
    std::string aerolinea;
    fechaHora salida;
    fechaHora llegada;
    int mat;

  public:
    //Constructor del objeto vuelo con todos los atriburos requeridos como parámetros
    explicit Vuelo(std::string p1,std::string p2,std::string p3,fechaHora p4,fechaHora p5,int p6)
    :origen(p1),destino(p2),aerolinea(p3),mat(p6),salida(p4),llegada(p5){
    }
    //Regresa la fecha de salida
    fechaHora getFechaSalida(){
      return salida;
    }
    //Regresa la fecha de llegada
    fechaHora getFechaLlegada(){
      return llegada;
    }
    //Regresa el lugar de origen
    std::string getOrigen(){
      return origen;
    }
    //Regresa el lugar de destino
    std::string getDestino(){
      return destino;
    }
    //Regresa el nombre de la aerolinea
    std::string getAerolinea(){
      return aerolinea;
    }
    //Regresa el numero de vuelo
    int getMat(){
      return mat;
    }
    //Cambia la fecha de salida
    void setFechaSalida(fechaHora fecha){
      salida=fecha;
    }
    //Cambia la fecha de llegada
    void setFechaLlegada(fechaHora fecha){
      llegada=fecha;
    }
    //Imprime todos los datos del vuelo
    std::string vuelostr(){
      std::string impresion = "Número de vuelo: "+std::to_string(mat)+"\nOrigen: " +origen+"\nDestino: "+destino+"\nAerolinea: "+aerolinea+"\n"+"Fecha de salida: "+salida.setString()+"Fecha de llegada: "+llegada.setString();
      return impresion;
    }
};

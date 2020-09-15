#include<string>

class fechaHora{
  //Se declaran los atributos de la clase de fecha y hora
  private:
    int anio;
    int mes;
    int dia;
    int hora;
    int minuto;
  public:
    //Constructor que pide como parametros todos los atributos
    explicit fechaHora(int dd, int mm, int aa, int h, int m){
      dia=dd;
      mes=mm;
      anio=aa;
      hora=h;
      minuto=m;
      revisar();
    }
    //Constructor por default que define los atributos con la fecha actual
    fechaHora(){
      dia=28;
      mes=11;
      anio=2019;
      hora=1;
      minuto=15;
    }
    //Pasar los datos que se tienen de fecha a un string al formato dd/mm/aa hh:mm
    std::string setString(){
      std::string x=""; //Variale que sirve para agregar un 0 si los minutos están compuestos por un solo dígito
      if (minuto<10){
        x="0";
      }
      std::string str=std::to_string(dia)+"/"+std::to_string(mes)+"/"+std::to_string(anio)+"    "+std::to_string(hora)+":"+x+std::to_string(minuto)+"\n";
      return str;
    }
    //Método para adelantar una fecha, se aumentan minutos y horas con parametros obtenidos
    void adelantar(int h, int m){
      minuto = minuto+m;
      hora = hora+h;
      revisar();
    }
    //Método para cambiar de hora,dia,mes y año cuando se haya llegado al límite de cada uno
    void revisar(){
      //Cambia hora cuando hay más de 60 minutos
      while (minuto>=60){
        int sobrante=minuto-60;
        minuto=sobrante;
        hora=hora+1;
      }
      //Cambia de dia cuando hay más de 24 horas
      while (hora>=24){
        int sob2=hora-24;
        hora=sob2;
        dia=dia+1;
      }
      //Cambio de mes para los meses que tienen 31 dias
      while (((mes==1)||(mes==3)||(mes==5)||(mes==7)||(mes==8)||(mes==10)||(mes==12))&&(dia>31)){
        int sob3=dia-31;
        dia=sob3;
        mes=mes+1;
      }
      //Cambio de mes para los meses que tienen 30 dias
      while ((mes==4||mes==6||mes==9||mes==11)&&(dia>30)){
        int sob4=dia-30;
        dia=sob4;
        mes=mes+1;
      }
      //Cambio de mes para febrero
      while ((mes==2)&&(dia>28)){
        int sob5=dia-28;
        dia=sob5;
        mes=mes+1;
      }
      //Cambio de año cuando hay más de 12 meses
      while(mes>12){
        int sob6=mes-12;
        mes=sob6;
        anio=anio+1;
      }
    }
    //Regresa el valor de dia
    int getDia(){
      return dia;
    }
    //Regresa el valor de mes
    int getMes(){
      return mes;
    }
    //Regresa el valor de año
    int getAnio(){
      return anio;
    }
    //Regresa el valor de hora
    int getHora(){
      return hora;
    }
    //Regresa el valor de minuto
    int getMinuto(){
      return minuto;
    }
};

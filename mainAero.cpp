#include<iostream>
#include<vector>
#include<sstream>
#include"Vuelo.h"
#include<fstream>
using namespace std;

int main() {
  bool menu=true;
  cout<<"Manejo de vuelos"<<endl;
  vector<Vuelo> vuelos;//Se declara un vector que contendra todos los vuelos
  //El while mostrará el menú hasta que el usuario decida salir
  while (menu=true){
    cout<<"\nMENU\n1. Ver vuelos\n2. Agregar vuelo\n3. Mostrar vuelos de una fecha especifica\n4. Actualizar vuelo retrasado\n5. Cargar vuelos desde archivo\n6. Guardar vuelos en archivo\n0. Salir\nSeleccione una opcion:";
    int seleccion;
    cin>>seleccion;

    //Opcion 1: Mostrar todos los vuelos
    if (seleccion==1){
      string impvuelo;
      //Se recorre todo el vector con el for para poder imprimir cada vuelo
      for (int i = 0; i < vuelos.size(); i++) {
        impvuelo="\nVuelo "+ to_string(i+1)+":\n"+vuelos[i].vuelostr();
        cout<<impvuelo;
      }
    }

    //Opcion 2:Agregar vuelo
    else if (seleccion==2){
      string origen,destino,aerolinea;
      int dia1,mes1,anio1,hora1,minuto1,dia2,mes2,anio2,hora2,minuto2,numVuelo;
      //Se piden todos los datos del vuelo que se quiere agregar
      cout<<"Escriba el número de vuelo: ";
      cin>>numVuelo;
      cout<<"Escriba el origen: "<<endl;
      getline(cin,origen);
      getline(cin,origen);
      cout<<"Escriba el destino: "<<endl;
      getline(cin,destino);
      cout<<"Escriba la aerolinea: "<<endl;
      getline(cin,aerolinea);
      cout<<"Escriba el día en que sale el vuelo: ";
      cin>>dia1;
      cout<<"Escriba el mes en que sale el vuelo: ";
      cin>>mes1;
      cout<<"Escriba el anio en que sale el vuelo: ";
      cin>>anio1;
      cout<<"Escribe la hora en que sale el vuelo: ";
      cin>>hora1;
      cout<<"Escribe el minuto en que sale el vuelo: ";
      cin>>minuto1;
      cout<<"Escriba el día en que llega el vuelo: ";
      cin>>dia2;
      cout<<"Escriba el mes en que llega el vuelo: ";
      cin>>mes2;
      cout<<"Escriba el anio en que llega el vuelo: ";
      cin>>anio2;
      cout<<"Escribe la hora en que llega el vuelo: ";
      cin>>hora2;
      cout<<"Escribe el minuto en que llega el vuelo: ";
      cin>>minuto2;
      //Se guardan los datos de las fechas en objetos tipo fechaHora
      fechaHora salida(dia1,mes1,anio1,hora1,minuto1);
      fechaHora llegada(dia2,mes2,anio2,hora2,minuto2);
      //Se agrega un nuevo vuelo al final del vector con los datos recabados
      Vuelo *v1;
      v1=new Vuelo(origen,destino,aerolinea,salida,llegada,numVuelo);
      vuelos.push_back(*v1);
    }

    //Opcion 3: Buscar vuelos por fecha
    else if (seleccion==3){
      int diaf,mesf,aniof,validar=-1;
      fechaHora fechan;
      string impbus;
      //Se piden los datos de la fecha buscada
      cout<<"Escriba el día de la fecha que desea buscar: ";
      cin>>diaf;
      cout<<"Escriba el mes de la fecha que desea buscar: ";
      cin>>mesf;
      cout<<"Escriba el anio de la fecha que desea buscar: ";
      cin>>aniof;
      cout<<"\nResultados:\n";
      //Se compara con cada uno de los vuelos del vector
      for (int i = 0; i < vuelos.size(); i++) {
        fechan=vuelos[i].getFechaSalida();
        //Si los datos coinciden exactamente con la fecha del vuelo, se muestra
        if (fechan.getDia()==diaf && fechan.getMes()==mesf && fechan.getAnio()==aniof){
          impbus=vuelos[i].vuelostr();
          cout<<impbus;
          validar=1;
        }
      }
      if(validar=-1){
        cout<<"Ningun vuelo encontrado\n";
      }
    }

    //Opcion 4: Atrasar un vuelo
    else if (seleccion==4){
      int numret,horaret,minutoret,validar=-1;
      //Se pide el numero de vuelo que desea ser modificado y el tiempo que esta atrasado
      cout<<"Introduzca el número del vuelo que desea retrasar: ";
      cin>>numret;
      cout<<"Cuántas horas está retrasado? ";
      cin>>horaret;
      cout<<"Cuántos minutos está retrasado? ";
      cin>>minutoret;
      //Se recorre el vector para buscar el vuelo
      for (int i = 0; i < vuelos.size(); i++) {
        //Si coinciden los numeros de vuelo se hace la modificacion
        if (vuelos[i].getMat()==numret){
          fechaHora salidaret;
          fechaHora llegadaret;
          //Se guardan las fechas que se quieren modificar en objetos FechaSalida
          salidaret=vuelos[i].getFechaSalida();
          llegadaret=vuelos[i].getFechaLlegada();
          //Se modifican los objetos con el método adelantar
          salidaret.adelantar(horaret,minutoret);
          llegadaret.adelantar(horaret,minutoret);
          //Se cambian las fechas de los vuelos con los objetos ya modificados
          vuelos[i].setFechaSalida(salidaret);
          vuelos[i].setFechaLlegada(llegadaret);
          cout<<"Vuelo retrasado con exito";
          validar=1;
        }
      }
      if (validar=-1){
        cout<<"No se encontro vuelo\n";
      }
    }

    //Opcion 5: Cargar vuelos de un archivo
    else if (seleccion==5){
      string nombrearchivo,a,origenl,destinol,aerolineal;
      ifstream lector;
      int nvuelos,diasl,messl,aniosl,horasl,minutosl,diall,mesll,anioll,horall,minutoll,numVuelol;
      //Se pide el nombre del archivo que se quiere cargar
      cout<<"Introduzca el nombre del archivo (incluya la terminacion .txt): ";
      cin>>nombrearchivo;
      //Se abre el archivo
      lector.open(nombrearchivo);
      //Si se abre con éxito se realiza todo el proceso
      if(lector.is_open()){
      //Se lee la primera linea, que es el numero de vuelos y lo convierte a entero
      lector>>a;
      nvuelos=stoi(a);
      getline(lector,a);
      //Se van a leer todos los datos de un vuelo el mismo número de veces que el número de vuelos que haya
      for (int i=0;i<nvuelos;i++){
        getline(lector,a);
        origenl=a;
        getline(lector,a);
        destinol=a;
        //Leer datos de fecha de salida
        getline(lector,a);
        diasl=stoi(a);
        getline(lector,a);
        messl=stoi(a);
        getline(lector,a);
        aniosl=stoi(a);
        getline(lector,a);
        horasl=stoi(a);
        getline(lector,a);
        minutosl=stoi(a);
        //Leer datos de llegada
        getline(lector,a);
        diall=stoi(a);
        getline(lector,a);
        mesll=stoi(a);
        getline(lector,a);
        anioll=stoi(a);
        getline(lector,a);
        horall=stoi(a);
        getline(lector,a);
        minutoll=stoi(a);
        //Leer aerolinea y numVuelo
        getline(lector,a);
        aerolineal=a;
        getline(lector,a);
        numVuelol=stoi(a);
        //Se agregan los datos de fecha a objetos fechaHora
        fechaHora fechasl(diasl,messl,aniosl,horasl,minutosl);
        fechaHora fechall(diall,mesll,anioll,horall,minutoll);
        //Agregar el vuelo al vector
        Vuelo *v2;
        v2=new Vuelo(origenl,destinol,aerolineal,fechasl,fechall,numVuelol);
        vuelos.push_back(*v2);
      }
      //Se cierra el archivo
      lector.close();
      cout<<"Vuelos cargados con exito.\n";
      }
      else{
        cout<<"No se pudo abrir el archivo.\n";
      }
    }

    //Opcion 6:Guardar todos los vuelos en un archivo
    else if (seleccion==6){
      ofstream escritor;
      string nombrearchivo2;
      //Se pide el nombre del archivo
      cout<<"Escriba el nombre con el que desea guardar su archivo (incluya la terminacion .txt): ";
      cin>>nombrearchivo2;
      //Se abre el archivo
      escritor.open(nombrearchivo2);
      //Si el archivo se abre con exito se realiza todo
      if (escritor.is_open()){
      //Se escribe en la primera linea del archivo el número de vuelos que hay
      escritor<<vuelos.size()<<endl;
      //Se van a escribir todos los datos de un vuelo el mismo número de veces que el número de vuelos que haya
      for(int i=0;i<vuelos.size();i++){
        escritor<<vuelos[i].getOrigen()<<endl;
        escritor<<vuelos[i].getDestino()<<endl;
        escritor<<vuelos[i].getFechaSalida().getDia()<<endl;
        escritor<<vuelos[i].getFechaSalida().getMes()<<endl;
        escritor<<vuelos[i].getFechaSalida().getAnio()<<endl;
        escritor<<vuelos[i].getFechaSalida().getHora()<<endl;
        escritor<<vuelos[i].getFechaSalida().getMinuto()<<endl;
        escritor<<vuelos[i].getFechaLlegada().getDia()<<endl;
        escritor<<vuelos[i].getFechaLlegada().getMes()<<endl;
        escritor<<vuelos[i].getFechaLlegada().getAnio()<<endl;
        escritor<<vuelos[i].getFechaLlegada().getHora()<<endl;
        escritor<<vuelos[i].getFechaLlegada().getMinuto()<<endl;
        escritor<<vuelos[i].getAerolinea()<<endl;
        escritor<<vuelos[i].getMat()<<endl;
      }
      //Se cierra el archivo
      escritor.close();
      cout<<"Vuelos guardados con exito\n";
    }
    else{
      cout<<"No se pudo abrir el archivo.\n";
    }
    }

    //Opcion 0: Salir
    else if (seleccion==0){
      break;//Se sale del ciclo
    }

    //Opcion no válida
    else{
      cout<<"Opcion invalida";
    }
  }
  return 0;
}

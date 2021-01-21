#ifndef COMPORTAMIENTOJUGADOR_H
#define COMPORTAMIENTOJUGADOR_H

#include "comportamientos/comportamiento.hpp"

#include <list>

struct estado {
  int fila;
  int columna;
  int orientacion;
  bool bikini, zapatillas;

  bool operator==(const estado& a){
    if(a.fila == fila && a.columna == columna && a.orientacion == orientacion && a.bikini == bikini && a.zapatillas == zapatillas)
      return true;
    else
      return false;
  }
};

class ComportamientoJugador : public Comportamiento {
  public:
    ComportamientoJugador(unsigned int size) : Comportamiento(size) {
      // Inicializar Variables de Estado
      fil = col = 99;
      brujula = 0; // 0: Norte, 1:Este, 2:Sur, 3:Oeste
      destino.fila = -1;
      destino.columna = -1;
      destino.orientacion = -1;
      hayplan=false;
      objetivo_actual_f = -1;
      objetivo_actual_c = -1;
      ubicacion_carga.fila = -1;
      ubicacion_carga.columna = -1;
      tiempo_restante = 3000;
      cargar = false;
      bikini = false;
      zapatillas = false;
      equipando_zapatillas = false;
      equipando_bikini = false;
      fotoMapa = mapaResultado;
    }
    ComportamientoJugador(std::vector< std::vector< unsigned char> > mapaR) : Comportamiento(mapaR) {
      // Inicializar Variables de Estado
      fil = col = 99;
      brujula = 0; // 0: Norte, 1:Este, 2:Sur, 3:Oeste
      destino.fila = -1;
      destino.columna = -1;
      destino.orientacion = -1;
      hayplan=false;
      objetivo_actual_f = -1;
      objetivo_actual_c = -1;
      ubicacion_carga.fila = -1;
      ubicacion_carga.columna = -1;
      tiempo_restante = 3000;
      cargar = false;
      bikini = false;
      zapatillas = false;
      equipando_zapatillas = false;
      equipando_bikini = false;
      fotoMapa = mapaResultado;
    }
    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    ~ComportamientoJugador(){}

    Action think(Sensores sensores);
    int interact(Action accion, int valor);
    void VisualizaPlan(const estado &st, const list<Action> &plan);
    ComportamientoJugador * clone(){return new ComportamientoJugador(*this);}

  private:
    // Declarar Variables de Estado
    int fil, col, brujula, tiempo_restante;
    estado actual, destino, ubicacion_carga;
    list<Action> plan;
    bool hayplan, zapatillas, bikini, cargar, equipando_zapatillas, equipando_bikini;
    int objetivo_actual_f, objetivo_actual_c;
    vector<vector<unsigned char>> fotoMapa;

    // Métodos privados de la clase
    bool pathFinding(int level, const estado &origen, const estado &destino, list<Action> &plan);
    bool pathFinding_Profundidad(const estado &origen, const estado &destino, list<Action> &plan);
    bool pathFinding_Anchura(const estado &origen, const estado &destino, list<Action> &plan);
    bool pathFinding_CostoUniforme(const estado &origen, const estado &destino, list<Action> &plan);
    bool pathFinding_Nivel2(const estado &origen, const estado &destino, list<Action> &plan);
    void asignarCasilla();
    void pintarMapa(Sensores sensores);
    bool casillaDesconocida(Sensores sensores);
    estado obtenerUbicacion(unsigned char x);
    void fotografiarMapa(vector<vector<unsigned char>>& fotoMapa);
    bool Cargar(Sensores sensores);
    int calcularRecarga(const estado &origen, const estado &destino, int &consumo, estado &final, int valor_interrogacion);
    void MejorCasillaCarga(int fila_carga, int columna_carga, int &consumo);

    void PintaPlan(list<Action> plan);
    bool HayObstaculoDelante(estado &st);

};

#endif

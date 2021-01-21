#include "../Comportamientos_Jugador/jugador.hpp"
#include "motorlib/util.h"

#include <iostream>
#include <utility>
#include <cmath>
#include <set>
#include <stack>
#include <queue>
#include <stdlib.h>

void ComportamientoJugador::pintarMapa(Sensores sensores){
	mapaResultado[actual.fila][actual.columna] = sensores.terreno[0];
	switch(sensores.sentido){
		case 0:
			mapaResultado[actual.fila-1][actual.columna-1] = sensores.terreno[1];
			mapaResultado[actual.fila-1][actual.columna] = sensores.terreno[2];
			mapaResultado[actual.fila-1][actual.columna+1] = sensores.terreno[3];
			mapaResultado[actual.fila-2][actual.columna-2] = sensores.terreno[4];
			mapaResultado[actual.fila-2][actual.columna-1] = sensores.terreno[5];
			mapaResultado[actual.fila-2][actual.columna] = sensores.terreno[6];
			mapaResultado[actual.fila-2][actual.columna+1] = sensores.terreno[7];
			mapaResultado[actual.fila-2][actual.columna+2] = sensores.terreno[8];
			mapaResultado[actual.fila-3][actual.columna-3] = sensores.terreno[9];
			mapaResultado[actual.fila-3][actual.columna-2] = sensores.terreno[10];
			mapaResultado[actual.fila-3][actual.columna-1] = sensores.terreno[11];
			mapaResultado[actual.fila-3][actual.columna] = sensores.terreno[12];
			mapaResultado[actual.fila-3][actual.columna+1] = sensores.terreno[13];
			mapaResultado[actual.fila-3][actual.columna+2] = sensores.terreno[14];
			mapaResultado[actual.fila-3][actual.columna+3] = sensores.terreno[15];
			break;
		case 1:
		 	mapaResultado[actual.fila-1][actual.columna+1] = sensores.terreno[1];
			mapaResultado[actual.fila][actual.columna+1] = sensores.terreno[2];
			mapaResultado[actual.fila+1][actual.columna+1] = sensores.terreno[3];
			mapaResultado[actual.fila-2][actual.columna+2] = sensores.terreno[4];
			mapaResultado[actual.fila-1][actual.columna+2] = sensores.terreno[5];
			mapaResultado[actual.fila][actual.columna+2] = sensores.terreno[6];
			mapaResultado[actual.fila+1][actual.columna+2] = sensores.terreno[7];
			mapaResultado[actual.fila+2][actual.columna+2] = sensores.terreno[8];
			mapaResultado[actual.fila-3][actual.columna+3] = sensores.terreno[9];
			mapaResultado[actual.fila-2][actual.columna+3] = sensores.terreno[10];
			mapaResultado[actual.fila-1][actual.columna+3] = sensores.terreno[11];
			mapaResultado[actual.fila][actual.columna+3] = sensores.terreno[12];
			mapaResultado[actual.fila+1][actual.columna+3] = sensores.terreno[13];
			mapaResultado[actual.fila+2][actual.columna+3] = sensores.terreno[14];
			mapaResultado[actual.fila+3][actual.columna+3] = sensores.terreno[15];
			break;
		case 2:
			mapaResultado[actual.fila+1][actual.columna+1] = sensores.terreno[1];
			mapaResultado[actual.fila+1][actual.columna] = sensores.terreno[2];
			mapaResultado[actual.fila+1][actual.columna-1] = sensores.terreno[3];
			mapaResultado[actual.fila+2][actual.columna+2] = sensores.terreno[4];
			mapaResultado[actual.fila+2][actual.columna+1] = sensores.terreno[5];
			mapaResultado[actual.fila+2][actual.columna] = sensores.terreno[6];
			mapaResultado[actual.fila+2][actual.columna-1] = sensores.terreno[7];
			mapaResultado[actual.fila+2][actual.columna-2] = sensores.terreno[8];
			mapaResultado[actual.fila+3][actual.columna+3] = sensores.terreno[9];
			mapaResultado[actual.fila+3][actual.columna+2] = sensores.terreno[10];
			mapaResultado[actual.fila+3][actual.columna+1] = sensores.terreno[11];
			mapaResultado[actual.fila+3][actual.columna] = sensores.terreno[12];
			mapaResultado[actual.fila+3][actual.columna-1] = sensores.terreno[13];
			mapaResultado[actual.fila+3][actual.columna-2] = sensores.terreno[14];
			mapaResultado[actual.fila+3][actual.columna-3] = sensores.terreno[15];
			break;
		case 3:
			mapaResultado[actual.fila+1][actual.columna-1] = sensores.terreno[1];
			mapaResultado[actual.fila][actual.columna-1] = sensores.terreno[2];
			mapaResultado[actual.fila-1][actual.columna-1] = sensores.terreno[3];
			mapaResultado[actual.fila+2][actual.columna-2] = sensores.terreno[4];
			mapaResultado[actual.fila+1][actual.columna-2] = sensores.terreno[5];
			mapaResultado[actual.fila][actual.columna-2] = sensores.terreno[6];
			mapaResultado[actual.fila-1][actual.columna-2] = sensores.terreno[7];
			mapaResultado[actual.fila-2][actual.columna-2] = sensores.terreno[8];
			mapaResultado[actual.fila+3][actual.columna-3] = sensores.terreno[9];
			mapaResultado[actual.fila+2][actual.columna-3] = sensores.terreno[10];
			mapaResultado[actual.fila+1][actual.columna-3] = sensores.terreno[11];
			mapaResultado[actual.fila][actual.columna-3] = sensores.terreno[12];
			mapaResultado[actual.fila-1][actual.columna-3] = sensores.terreno[13];
			mapaResultado[actual.fila-2][actual.columna-3] = sensores.terreno[14];
			mapaResultado[actual.fila-3][actual.columna-3] = sensores.terreno[15];
			break;
	}
}

bool ComportamientoJugador::casillaDesconocida(Sensores sensores){
	bool result = false;

	switch(sensores.sentido){
		case 0:
			if(fotoMapa[actual.fila-1][actual.columna-1] == '?' ||
				 fotoMapa[actual.fila-1][actual.columna] == '?' ||
				 fotoMapa[actual.fila-1][actual.columna+1] == '?' ||
				 fotoMapa[actual.fila-2][actual.columna-2] == '?' ||
				 fotoMapa[actual.fila-2][actual.columna-1] == '?' ||
				 fotoMapa[actual.fila-2][actual.columna] == '?' ||
				 fotoMapa[actual.fila-2][actual.columna+1] == '?' ||
				 fotoMapa[actual.fila-2][actual.columna+2] == '?' ||
				 fotoMapa[actual.fila-3][actual.columna-3] == '?' ||
				 fotoMapa[actual.fila-3][actual.columna-2] == '?' ||
				 fotoMapa[actual.fila-3][actual.columna-1] == '?' ||
				 fotoMapa[actual.fila-3][actual.columna] == '?' ||
				 fotoMapa[actual.fila-3][actual.columna+1] == '?' ||
				 fotoMapa[actual.fila-3][actual.columna+2] == '?' ||
				 fotoMapa[actual.fila-3][actual.columna+3] == '?')
				 result = true;
			break;
		case 1:
		 	if(fotoMapa[actual.fila-1][actual.columna+1] == '?' ||
				 fotoMapa[actual.fila][actual.columna+1] == '?' ||
				 fotoMapa[actual.fila+1][actual.columna+1] == '?' ||
				 fotoMapa[actual.fila-2][actual.columna+2] == '?' ||
				 fotoMapa[actual.fila-1][actual.columna+2] == '?' ||
				 fotoMapa[actual.fila][actual.columna+2] == '?' ||
				 fotoMapa[actual.fila+1][actual.columna+2] == '?' ||
	  		 fotoMapa[actual.fila+2][actual.columna+2] == '?' ||
				 fotoMapa[actual.fila-3][actual.columna+3] == '?' ||
				 fotoMapa[actual.fila-2][actual.columna+3] == '?' ||
				 fotoMapa[actual.fila-1][actual.columna+3] == '?' ||
				 fotoMapa[actual.fila][actual.columna+3] == '?' ||
				 fotoMapa[actual.fila+1][actual.columna+3] == '?' ||
				 fotoMapa[actual.fila+2][actual.columna+3] == '?' ||
				 fotoMapa[actual.fila+3][actual.columna+3] == '?')
				 result = true;
			break;
		case 2:
			if(fotoMapa[actual.fila+1][actual.columna+1] == '?' ||
				 fotoMapa[actual.fila+1][actual.columna] == '?' ||
				 fotoMapa[actual.fila+1][actual.columna-1] == '?' ||
				 fotoMapa[actual.fila+2][actual.columna+2] == '?' ||
				 fotoMapa[actual.fila+2][actual.columna+1] == '?' ||
				 fotoMapa[actual.fila+2][actual.columna] == '?' ||
				 fotoMapa[actual.fila+2][actual.columna-1] == '?' ||
				 fotoMapa[actual.fila+2][actual.columna-2] == '?' ||
				 fotoMapa[actual.fila+3][actual.columna+3] == '?' ||
				 fotoMapa[actual.fila+3][actual.columna+2] == '?' ||
				 fotoMapa[actual.fila+3][actual.columna+1] == '?' ||
				 fotoMapa[actual.fila+3][actual.columna] == '?' ||
				 fotoMapa[actual.fila+3][actual.columna-1] == '?' ||
				 fotoMapa[actual.fila+3][actual.columna-2] == '?' ||
				 fotoMapa[actual.fila+3][actual.columna-3] == '?')
				 result = true;
			break;
		case 3:
			if(fotoMapa[actual.fila+1][actual.columna-1] == '?' ||
				 fotoMapa[actual.fila][actual.columna-1] == '?' ||
				 fotoMapa[actual.fila-1][actual.columna-1] == '?' ||
				 fotoMapa[actual.fila+2][actual.columna-2] == '?' ||
				 fotoMapa[actual.fila+1][actual.columna-2] == '?' ||
			   fotoMapa[actual.fila][actual.columna-2] == '?' ||
				 fotoMapa[actual.fila-1][actual.columna-2] == '?' ||
			   fotoMapa[actual.fila-2][actual.columna-2] == '?' ||
				 fotoMapa[actual.fila+3][actual.columna-3] == '?' ||
				 fotoMapa[actual.fila+2][actual.columna-3] == '?' ||
				 fotoMapa[actual.fila+1][actual.columna-3] == '?' ||
				 fotoMapa[actual.fila][actual.columna-3] == '?' ||
				 fotoMapa[actual.fila-1][actual.columna-3] == '?' ||
				 fotoMapa[actual.fila-2][actual.columna-3] == '?' ||
				 fotoMapa[actual.fila-3][actual.columna-3] == '?')
				 result = true;
			break;
	}

	return result;
}

void ComportamientoJugador::fotografiarMapa(vector<vector<unsigned char>>& fotoMapa){
	for(int i = 0; i < mapaResultado.size(); i++)
		for(int j = 0; j < mapaResultado[i].size(); j++)
			fotoMapa[i][j] = mapaResultado[i][j];
}

bool hayZapatillas(Sensores sensores){
	bool result = false;

	for(int i = 0; i < 16; i++)
		if(sensores.terreno[i] == 'D')
			result = true;

	return result;
}

bool hayBikini(Sensores sensores){
	bool result = false;

	for(int i = 0; i < 16; i++)
		if(sensores.terreno[i] == 'K')
			result = true;

	return result;
}

estado ComportamientoJugador::obtenerUbicacion(unsigned char x){
	estado result;
	bool fin = false;

	for(int i = 0; i < mapaResultado.size() && !fin; i++){
		for(int j = 0; j < mapaResultado[i].size() && !fin; j++)
			if(mapaResultado[i][j] == x){
				result.fila = i;
				result.columna = j;
				fin = true;
			}
	}

	return result;
}

void ComportamientoJugador::MejorCasillaCarga(int fila_carga, int columna_carga, int &consumo){
	estado carga;
	carga.fila = fila_carga;
	carga.columna = columna_carga;

	calcularRecarga(actual, carga, consumo, carga, 100);
}

// Asignar casilla de cargar
void ComportamientoJugador::asignarCasilla(){
	int consumo = 1000000;
	int consumo_aux;

	for(int i = 0; i < mapaResultado.size(); i++){
		for(int j = 0; j < mapaResultado[i].size(); j++){
			if(mapaResultado[i][j] == 'X'){
				MejorCasillaCarga(i, j, consumo_aux);
				if(consumo_aux < consumo){
					ubicacion_carga.fila = i;
					ubicacion_carga.columna = j;
					consumo = consumo_aux;
				}
			}
		}
	}
}

bool ComportamientoJugador::Cargar(Sensores sensores){
	bool result = false;
	int consumo_1 = 0, consumo_2 = 0, consumo_total = 0, num_movimientos = 0;
	estado final;

	asignarCasilla();
	num_movimientos = calcularRecarga(actual, destino, consumo_1, final, 2);
	consumo_total = consumo_1;
	num_movimientos += calcularRecarga(final, ubicacion_carga, consumo_2, final, 2);
	consumo_total += consumo_2;

	if(consumo_total > sensores.bateria && (num_movimientos + 50) < tiempo_restante){
		result = true;
	}


	return result;
}

// Este es el método principal que debe contener los 4 Comportamientos_Jugador
// que se piden en la práctica. Tiene como entrada la información de los
// sensores y devuelve la acción a realizar.
Action ComportamientoJugador::think(Sensores sensores) {
	Action accion = actIDLE;
	//SABER EN EL MAPA EN EL QUE ESTAMOS
	actual.fila        = sensores.posF;
	actual.columna     = sensores.posC;
	actual.orientacion = sensores.sentido;
	destino.fila       = sensores.destinoF;
	destino.columna    = sensores.destinoC;

	pintarMapa(sensores);

	// Si delante hay agua o bosque y antes del plan alguna casilla del sensor era interrogacion
	bool desconocido = casillaDesconocida(sensores);
	bool rehacer_plan_carga = false;
	if((sensores.terreno[2] == 'A' || sensores.terreno[2] == 'B') && sensores.nivel == 4 && desconocido){
		hayplan = false;
		rehacer_plan_carga = true;
	}

	// Hace falta cargar
	if(((actual.fila == objetivo_actual_f && actual.columna == objetivo_actual_c) || rehacer_plan_carga) && !cargar && sensores.bateria < 800){
		cargar = Cargar(sensores);

		if(cargar)
			hayplan = false;
	}

	// Si hay un nuevo destino
	if(sensores.destinoF != objetivo_actual_f || sensores.destinoC != objetivo_actual_c){
		hayplan = false;
		objetivo_actual_f = sensores.destinoF;
		objetivo_actual_c = sensores.destinoC;
	}

	// Si va a chocar o se va a caer por el precipicio
	if(hayplan && plan.front() == actFORWARD && (sensores.terreno[2] == 'M' || sensores.terreno[2] == 'P'))
			hayplan = false;

	// Si necesita cargarse
	if(cargar && !hayplan && (ubicacion_carga.fila != -1 && ubicacion_carga.columna != -1)){
		fotografiarMapa(fotoMapa);
		hayplan = pathFinding(sensores.nivel, actual, ubicacion_carga, plan);
	}else{
		// Mirar si hemos pasado encima de zapatillas o de bikini
		if(sensores.terreno[0] == 'K')
			bikini = true;
		if(sensores.terreno[0] == 'D')
			zapatillas = true;

		// Si no hay plan lo crea
		if(!hayplan){
			fotografiarMapa(fotoMapa);
			hayplan = pathFinding(sensores.nivel, actual, destino, plan);
		}
	}

	//Recoger zapatillas o bikini
	if((!bikini || !zapatillas) && (sensores.nivel == 4)){
		if((hayZapatillas(sensores) && !zapatillas) || equipando_zapatillas){
			estado ubi_zapatillas;
			unsigned char x = 'D';
			ubi_zapatillas = obtenerUbicacion(x);
			equipando_zapatillas = true;

			fotografiarMapa(fotoMapa);
			hayplan = pathFinding (sensores.nivel, actual, ubi_zapatillas, plan);
		}else if((hayBikini(sensores) && !bikini) || equipando_bikini){
			estado ubi_bikini;
			unsigned char x = 'K';
			ubi_bikini = obtenerUbicacion(x);
			equipando_bikini = true;

			fotografiarMapa(fotoMapa);
			hayplan = pathFinding (sensores.nivel, actual, ubi_bikini, plan);
		}
	}

	// Si hay plan
	if((hayplan) && plan.size() > 0){
		if(sensores.nivel != 4){
				accion = plan.front();
				plan.pop_front();
		}else{
			if(sensores.superficie[2] == 'a' && plan.front() == actFORWARD){
				accion == actIDLE;
			}else{
				accion = plan.front();
				plan.pop_front();
			}
		}
	}else{
		if(cargar && actual.fila == ubicacion_carga.fila && actual.columna == ubicacion_carga.columna){
			if(sensores.bateria < 3000 && sensores.bateria <= 2*tiempo_restante){
				accion == actIDLE;
			}else{
				cargar = false;
				hayplan = false;
			}
		}else if(equipando_bikini){
			hayplan = false;
			equipando_bikini = false;
		}else if(equipando_zapatillas){
			hayplan = false;
			equipando_zapatillas = false;
		}
	}

	tiempo_restante--;

  return accion;
}


// Llama al algoritmo de busqueda que se usará en cada comportamiento del agente
// Level representa el comportamiento en el que fue iniciado el agente.
bool ComportamientoJugador::pathFinding (int level, const estado &origen, const estado &destino, list<Action> &plan){
	switch (level){
		case 1: cout << "Busqueda en profundad\n";
			      return pathFinding_Profundidad(origen,destino,plan);
						break;
		case 2: cout << "Busqueda en Anchura\n";
			      return pathFinding_Anchura(origen,destino,plan);
						break;
		case 3: cout << "Busqueda Costo Uniforme\n";
						return pathFinding_CostoUniforme(origen,destino,plan);
						break;
		case 4: cout << "Busqueda para el reto\n";
						return pathFinding_Nivel2(origen,destino,plan);
						break;
	}
	cout << "Comportamiento sin implementar\n";
	return false;
}


//---------------------- Implementación de la busqueda en profundidad ---------------------------

// Dado el código en carácter de una casilla del mapa dice si se puede
// pasar por ella sin riegos de morir o chocar.
bool EsObstaculo(unsigned char casilla){
	if (casilla=='P' or casilla=='M')
		return true;
	else
	  return false;
}


// Comprueba si la casilla que hay delante es un obstaculo. Si es un
// obstaculo devuelve true. Si no es un obstaculo, devuelve false y
// modifica st con la posición de la casilla del avance.
bool ComportamientoJugador::HayObstaculoDelante(estado &st){
	int fil=st.fila, col=st.columna;

  // calculo cual es la casilla de delante del agente
	switch (st.orientacion) {
		case 0: fil--; break;
		case 1: col++; break;
		case 2: fil++; break;
		case 3: col--; break;
	}

	// Compruebo que no me salgo fuera del rango del mapa
	if (fil<0 or fil>=mapaResultado.size()) return true;
	if (col<0 or col>=mapaResultado[0].size()) return true;

	// Miro si en esa casilla hay un obstaculo infranqueable
	if (!EsObstaculo(mapaResultado[fil][col])){
		// No hay obstaculo, actualizo el parámetro st poniendo la casilla de delante.
    st.fila = fil;
		st.columna = col;
		return false;
	}
	else{
	  return true;
	}
}

struct nodo{
	estado st;
	list<Action> secuencia;
};

struct nodoCosto{
	estado st;
	list<Action> secuencia;
	int costo;
	bool operator<(nodoCosto a) const{
		return costo > a.costo;
	}
};

struct nodoEstrella{
	estado padre;
	estado st;
	Action accion;
	int g, h; // costo y heuristica
	bool operator<(nodoEstrella a) const{
		return g+h > a.g+a.h;
	}
};

struct ComparaEstados{
	bool operator()(const estado &a, const estado &n) const{
		if ((a.fila > n.fila) or (a.fila == n.fila and a.columna > n.columna) or
	      (a.fila == n.fila and a.columna == n.columna and a.orientacion > n.orientacion) or
				(a.fila == n.fila and a.columna == n.columna and a.orientacion == n.orientacion and a.bikini < n.bikini) or
				(a.fila == n.fila and a.columna == n.columna and a.orientacion == n.orientacion and a.bikini == n.bikini and a.zapatillas < n.zapatillas))
			return true;
		else
			return false;
	}
};

// Implementación de la búsqueda en profundidad.
// Entran los puntos origen y destino y devuelve la
// secuencia de acciones en plan, una lista de acciones.
bool ComportamientoJugador::pathFinding_Profundidad(const estado &origen, const estado &destino, list<Action> &plan) {
	//Borro la lista
	cout << "Calculando plan\n";
	plan.clear();
	set<estado,ComparaEstados> generados; // Lista de Cerrados
	stack<nodo> pila;											// Lista de Abiertos

  nodo current;
	current.st = origen;
	current.secuencia.empty();

	pila.push(current);

  while (!pila.empty() and (current.st.fila!=destino.fila or current.st.columna != destino.columna)){

		pila.pop();
		generados.insert(current.st);

		// Generar descendiente de girar a la derecha
		nodo hijoTurnR = current;
		hijoTurnR.st.orientacion = (hijoTurnR.st.orientacion+1)%4;
		if (generados.find(hijoTurnR.st) == generados.end()){
			hijoTurnR.secuencia.push_back(actTURN_R);
			pila.push(hijoTurnR);

		}

		// Generar descendiente de girar a la izquierda
		nodo hijoTurnL = current;
		hijoTurnL.st.orientacion = (hijoTurnL.st.orientacion+3)%4;
		if (generados.find(hijoTurnL.st) == generados.end()){
			hijoTurnL.secuencia.push_back(actTURN_L);
			pila.push(hijoTurnL);
		}

		// Generar descendiente de avanzar
		nodo hijoForward = current;
		if (!HayObstaculoDelante(hijoForward.st)){
			if (generados.find(hijoForward.st) == generados.end()){
				hijoForward.secuencia.push_back(actFORWARD);
				pila.push(hijoForward);
			}
		}

		// Tomo el siguiente valor de la pila
		if (!pila.empty()){
			current = pila.top();
		}
	}

  cout << "Terminada la busqueda\n";

	if (current.st.fila == destino.fila and current.st.columna == destino.columna){
		cout << "Cargando el plan\n";
		plan = current.secuencia;
		cout << "Longitud del plan: " << plan.size() << endl;
		PintaPlan(plan);
		// ver el plan en el mapa
		VisualizaPlan(origen, plan);
		return true;
	}
	else {
		cout << "No encontrado plan\n";
	}


	return false;
}

// Implementación de la búsqueda en anchura.
// Entran los puntos origen y destino y devuelve la
// secuencia de acciones en plan, una lista de acciones.
bool ComportamientoJugador::pathFinding_Anchura(const estado &origen, const estado &destino, list<Action> &plan) {
	nodo current;
	set<estado,ComparaEstados> explorados;
	queue<nodo> explorar;
	int fila, colum;

	current.st = origen;
	current.secuencia.empty();    //No hay acciones porque es el origen
	current.st.bikini = false;
	current.st.zapatillas = false;

	//Metemos el nodo origen y su costo en la lista
	explorar.push(current);

	while(!explorar.empty() && (current.st.fila != destino.fila || current.st.columna != destino.columna)){
		explorar.pop();

		if(explorados.find(current.st) == explorados.end()){
			explorados.insert(current.st);

			fila = current.st.fila;
			colum = current.st.columna;

			// Generar descendiente de girar a la derecha
			nodo hijoTurnR = current;

			hijoTurnR.st.orientacion = (hijoTurnR.st.orientacion+1)%4;
			if (explorados.find(hijoTurnR.st) == explorados.end()){   // Si no se ha explorado aun
				hijoTurnR.secuencia.push_back(actTURN_R);
				explorar.push(hijoTurnR);
			}

			// Generar descendiente de girar a la izquierda
			nodo hijoTurnL = current;

			hijoTurnL.st.orientacion = (hijoTurnL.st.orientacion+3)%4;
			if (explorados.find(hijoTurnL.st) == explorados.end()){   // Si no se ha explorado aun
				hijoTurnL.secuencia.push_back(actTURN_L);
				explorar.push(hijoTurnL);
			}

			// Generar descendiente de avanzar
			nodo hijoForward = current;

			if (!HayObstaculoDelante(hijoForward.st)){
				fila = hijoForward.st.fila;
				colum = hijoForward.st.columna;

				if (explorados.find(hijoForward.st) == explorados.end()){   // Si no se ha explorado aun
					hijoForward.secuencia.push_back(actFORWARD);
					explorar.push(hijoForward);
				}
			}
		}

		// Tomo el siguiente valor de la pila
		if (!explorar.empty()){
			current = explorar.front();
		}
	}

	cout << "Terminada la busqueda\n";

	if (current.st.fila == destino.fila and current.st.columna == destino.columna){
		cout << "Cargando el plan\n";
		plan = current.secuencia;
		cout << "Longitud del plan: " << plan.size() << endl;
		PintaPlan(plan);
		// ver el plan en el mapa
		VisualizaPlan(origen, plan);
		return true;
	}
	else {
		cout << "No encontrado plan\n";
	}

	return false;
}

// Implementación de la búsqueda de costo uniforme.
// Entran los puntos origen y destino y devuelve la
// secuencia de acciones en plan, una lista de acciones.
bool ComportamientoJugador::pathFinding_CostoUniforme(const estado &origen, const estado &destino, list<Action> &plan) {
	nodoCosto current;
	set<estado,ComparaEstados> explorados;
	priority_queue<nodoCosto> explorar;
	int fila, colum;

	current.st = origen;
  current.secuencia.empty();    //No hay acciones porque es el origen
  current.costo = 0;
	current.st.bikini = false;
	current.st.zapatillas = false;

  //Metemos el nodo origen y su costo en la lista
  explorar.push(current);

  while(!explorar.empty() && (current.st.fila != destino.fila || current.st.columna != destino.columna)){
		explorar.pop();

		if(explorados.find(current.st) == explorados.end()){
			explorados.insert(current.st);

			fila = current.st.fila;
			colum = current.st.columna;

			//Mirar si son las zapatillas o el bikini
			if(mapaResultado[fila][colum] == 'K'){
				current.st.bikini = true;
			}
			if(mapaResultado[fila][colum] == 'D'){
				current.st.zapatillas = true;
			}

			//Mirar costo de la acción
			if(mapaResultado[fila][colum] == 'A'){
				if(current.st.bikini)
					current.costo += 10;
				else
					current.costo += 100;
			}else if(mapaResultado[fila][colum] == 'B'){
				if(current.st.zapatillas)
					current.costo += 5;
				else
					current.costo += 50;
			}else if(mapaResultado[fila][colum] == 'T'){
				current.costo += 2;
			}else{
				current.costo += 1;
			}

			// Generar descendiente de girar a la derecha
			nodoCosto hijoTurnR = current;

			hijoTurnR.st.orientacion = (hijoTurnR.st.orientacion+1)%4;
			if (explorados.find(hijoTurnR.st) == explorados.end()){   // Si no se ha explorado aun
				hijoTurnR.secuencia.push_back(actTURN_R);
				explorar.push(hijoTurnR);
			}

			// Generar descendiente de girar a la izquierda
			nodoCosto hijoTurnL = current;

			hijoTurnL.st.orientacion = (hijoTurnL.st.orientacion+3)%4;
			if (explorados.find(hijoTurnL.st) == explorados.end()){   // Si no se ha explorado aun
				hijoTurnL.secuencia.push_back(actTURN_L);
				explorar.push(hijoTurnL);
			}

			// Generar descendiente de avanzar
			nodoCosto hijoForward = current;

			if (!HayObstaculoDelante(hijoForward.st)){
				fila = hijoForward.st.fila;
				colum = hijoForward.st.columna;

				if (explorados.find(hijoForward.st) == explorados.end()){   // Si no se ha explorado aun
					hijoForward.secuencia.push_back(actFORWARD);
					explorar.push(hijoForward);
				}
			}
		}

		// Tomo el siguiente valor de la pila
		if (!explorar.empty()){
			current = explorar.top();
		}
	}

	cout << "Terminada la busqueda\n";
	cout << "Coste del plan: " << current.costo << "\n";

	if (current.st.fila == destino.fila and current.st.columna == destino.columna){
		cout << "Cargando el plan\n";
		plan = current.secuencia;
		cout << "Longitud del plan: " << plan.size() << endl;
		PintaPlan(plan);
		// ver el plan en el mapa
		VisualizaPlan(origen, plan);
		return true;
	}
	else {
		cout << "No encontrado plan\n";
	}

	return false;
}

int calcularH(int fila_destino, int columna_destino, int fila, int columna){
	return (abs(fila_destino-fila) + abs(columna_destino-columna));
}

void actualizarExplorados(list<nodoEstrella>& lista_explorados, nodoEstrella current, priority_queue<nodoEstrella>& explorar, set<estado,ComparaEstados>& explorados){
	bool encontrado = false;

	for(list<nodoEstrella>::iterator it = lista_explorados.begin(); it != lista_explorados.end() && !encontrado; ++it){
		if((*it).st == current.st){
			encontrado = true;

			if((*it).g > current.g){
				explorar.push(current);
				lista_explorados.erase(it);
				explorados.erase(explorados.find(current.st));
			}
		}
	}
}

list<Action> obtenerPlan(list<nodoEstrella> lista_explorados, nodoEstrella current){
	list<Action> plan;

	for(list<nodoEstrella>::iterator it = lista_explorados.begin(); it != lista_explorados.end() && (*it).accion != actIDLE; ++it){
		if((*it).st == current.st){
			plan.push_front((*it).accion);
			current.st = (*it).padre;
		}
	}

	return plan;
}

// Implementación de la búsqueda de costo uniforme para el nivel 2
bool ComportamientoJugador::pathFinding_Nivel2(const estado &origen, const estado &destino, list<Action> &plan) {
	nodoEstrella current;
	set<estado,ComparaEstados> explorados;
	priority_queue<nodoEstrella> explorar;
	list<nodoEstrella> lista_explorados;
	int fila, colum, h;

	current.st = origen;
  current.accion = actIDLE;    //No hay acciones porque es el origen
  current.h = calcularH(destino.fila, destino.columna, current.st.fila, current.st.columna);
	current.g = 0;
	current.st.bikini = bikini;
	current.st.zapatillas = zapatillas;
	current.padre.fila = -1;
	current.padre.columna = -1;

  //Metemos el nodo origen y su costo en la lista
  explorar.push(current);

  while(!explorar.empty() && (current.st.fila != destino.fila || current.st.columna != destino.columna)){
		explorar.pop();

		if(explorados.find(current.st) == explorados.end()){
			explorados.insert(current.st);
			lista_explorados.push_front(current);

			fila = current.st.fila;
			colum = current.st.columna;

			//Guardamos el padre
			current.padre = current.st;

			//Mirar si son las zapatillas o el bikini
			if(!bikini && mapaResultado[fila][colum] == 'K'){
				current.st.bikini = true;
			}
			if(!zapatillas && mapaResultado[fila][colum] == 'D'){
				current.st.zapatillas = true;
			}

			//Mirar costo de la acción
			if(mapaResultado[fila][colum] == 'A'){
				if(current.st.bikini)
					current.g += 10;
				else
					current.g += 100;
			}else if(mapaResultado[fila][colum] == 'B'){
				if(current.st.zapatillas)
					current.g += 5;
				else
					current.g += 50;
			}else if(mapaResultado[fila][colum] == '?'){
				current.g += 2;
			}else if(mapaResultado[fila][colum] == 'T'){
				current.g += 2;
			}else{
				current.g += 1;
			}

			//Calculamos la F
			current.h = calcularH(destino.fila, destino.columna, current.st.fila, current.st.columna);

			// Generar descendiente de girar a la derecha
			nodoEstrella hijoTurnR = current;

			hijoTurnR.st.orientacion = (hijoTurnR.st.orientacion+1)%4;
			if (explorados.find(hijoTurnR.st) == explorados.end()){   // Si no se ha explorado aun
				hijoTurnR.accion = actTURN_R;
				explorar.push(hijoTurnR);
			}else{
				actualizarExplorados(lista_explorados, hijoTurnR, explorar, explorados);
			}

			// Generar descendiente de girar a la izquierda
			nodoEstrella hijoTurnL = current;

			hijoTurnL.st.orientacion = (hijoTurnL.st.orientacion+3)%4;
			if (explorados.find(hijoTurnL.st) == explorados.end()){   // Si no se ha explorado aun
				hijoTurnL.accion = actTURN_L;
				explorar.push(hijoTurnL);
			}else{
				actualizarExplorados(lista_explorados, hijoTurnL, explorar, explorados);
			}

			// Generar descendiente de avanzar
			nodoEstrella hijoForward = current;

			if (!HayObstaculoDelante(hijoForward.st)){
				//Calculamos la F
				hijoForward.h = calcularH(destino.fila, destino.columna, hijoForward.st.fila, hijoForward.st.columna);

				if (explorados.find(hijoForward.st) == explorados.end()){   // Si no se ha explorado aun
					hijoForward.accion = actFORWARD ;
					explorar.push(hijoForward);
				}else{
					actualizarExplorados(lista_explorados, hijoForward, explorar, explorados);
				}
			}
		}else{
			actualizarExplorados(lista_explorados, current, explorar, explorados);
		}

		// Tomo el siguiente valor de la pila
		if (!explorar.empty()){
			current = explorar.top();
		}
	}

	lista_explorados.push_front(current);

	cout << "Terminada la busqueda\n";
	cout << "Coste del plan: " << current.g << "\n";

	if (current.st.fila == destino.fila and current.st.columna == destino.columna){
		cout << "Cargando el plan\n";
		plan = obtenerPlan(lista_explorados, current);
		cout << "Longitud del plan: " << plan.size() << endl;
		PintaPlan(plan);
		// ver el plan en el mapa
		VisualizaPlan(origen, plan);
		return true;
	}
	else {
		cout << "No encontrado plan\n";
	}

	return false;
}

int ComportamientoJugador::calcularRecarga(const estado &origen, const estado &destino, int &consumo, estado &final, int valor_interrogacion){
	nodoEstrella current;
	set<estado,ComparaEstados> explorados;
	priority_queue<nodoEstrella> explorar;
	list<nodoEstrella> lista_explorados;
	int fila, colum, h;
	list<Action> result;

	current.st = origen;
  current.accion = actIDLE;    //No hay acciones porque es el origen
  current.h = calcularH(destino.fila, destino.columna, current.st.fila, current.st.columna);
	current.g = 0;
	current.st.bikini = bikini;
	current.st.zapatillas = zapatillas;
	current.padre.fila = -1;
	current.padre.columna = -1;

  //Metemos el nodo origen y su costo en la lista
  explorar.push(current);

  while(!explorar.empty() && (current.st.fila != destino.fila || current.st.columna != destino.columna)){
		explorar.pop();

		if(explorados.find(current.st) == explorados.end()){
			explorados.insert(current.st);
			lista_explorados.push_front(current);

			fila = current.st.fila;
			colum = current.st.columna;

			//Guardamos el padre
			current.padre = current.st;

			//Mirar si son las zapatillas o el bikini
			if(!bikini && mapaResultado[fila][colum] == 'K'){
				current.st.bikini = true;
			}
			if(!zapatillas && mapaResultado[fila][colum] == 'D'){
				current.st.zapatillas = true;
			}

			//Mirar costo de la acción
			if(mapaResultado[fila][colum] == 'A'){
				if(current.st.bikini)
					current.g += 10;
				else
					current.g += 100;
			}else if(mapaResultado[fila][colum] == 'B'){
				if(current.st.zapatillas)
					current.g += 5;
				else
					current.g += 50;
			}else if(mapaResultado[fila][colum] == '?'){
				current.g += valor_interrogacion;
			}else if(mapaResultado[fila][colum] == 'T'){
				current.g += 2;
			}else{
				current.g += 1;
			}

			//Calculamos la F
			current.h = calcularH(destino.fila, destino.columna, current.st.fila, current.st.columna);

			// Generar descendiente de girar a la derecha
			nodoEstrella hijoTurnR = current;

			hijoTurnR.st.orientacion = (hijoTurnR.st.orientacion+1)%4;
			if (explorados.find(hijoTurnR.st) == explorados.end()){   // Si no se ha explorado aun
				hijoTurnR.accion = actTURN_R;
				explorar.push(hijoTurnR);
			}else{
				actualizarExplorados(lista_explorados, hijoTurnR, explorar, explorados);
			}

			// Generar descendiente de girar a la izquierda
			nodoEstrella hijoTurnL = current;

			hijoTurnL.st.orientacion = (hijoTurnL.st.orientacion+3)%4;
			if (explorados.find(hijoTurnL.st) == explorados.end()){   // Si no se ha explorado aun
				hijoTurnL.accion = actTURN_L;
				explorar.push(hijoTurnL);
			}else{
				actualizarExplorados(lista_explorados, hijoTurnL, explorar, explorados);
			}

			// Generar descendiente de avanzar
			nodoEstrella hijoForward = current;

			if (!HayObstaculoDelante(hijoForward.st)){
				//Calculamos la F
				hijoForward.h = calcularH(destino.fila, destino.columna, hijoForward.st.fila, hijoForward.st.columna);

				if (explorados.find(hijoForward.st) == explorados.end()){   // Si no se ha explorado aun
					hijoForward.accion = actFORWARD ;
					explorar.push(hijoForward);
				}else{
					actualizarExplorados(lista_explorados, hijoForward, explorar, explorados);
				}
			}
		}else{
			actualizarExplorados(lista_explorados, current, explorar, explorados);
		}

		// Tomo el siguiente valor de la pila
		if (!explorar.empty()){
			current = explorar.top();
		}
	}

	lista_explorados.push_front(current);

	result = obtenerPlan(lista_explorados, current);
 	consumo = current.g;
	final = current.st;

	if (current.st.fila == destino.fila and current.st.columna == destino.columna)
		return result.size();
	else
		return -1;
}


// Sacar por la términal la secuencia del plan obtenido
void ComportamientoJugador::PintaPlan(list<Action> plan) {
	auto it = plan.begin();
	while (it!=plan.end()){
		if (*it == actFORWARD){
			cout << "A ";
		}
		else if (*it == actTURN_R){
			cout << "D ";
		}
		else if (*it == actTURN_L){
			cout << "I ";
		}
		else {
			cout << "- ";
		}
		it++;
	}
	cout << endl;
}



void AnularMatriz(vector<vector<unsigned char> > &m){
	for (int i=0; i<m[0].size(); i++){
		for (int j=0; j<m.size(); j++){
			m[i][j]=0;
		}
	}
}


// Pinta sobre el mapa del juego el plan obtenido
void ComportamientoJugador::VisualizaPlan(const estado &st, const list<Action> &plan){
  AnularMatriz(mapaConPlan);
	estado cst = st;

	auto it = plan.begin();
	while (it!=plan.end()){
		if (*it == actFORWARD){
			switch (cst.orientacion) {
				case 0: cst.fila--; break;
				case 1: cst.columna++; break;
				case 2: cst.fila++; break;
				case 3: cst.columna--; break;
			}
			mapaConPlan[cst.fila][cst.columna]=1;
		}
		else if (*it == actTURN_R){
			cst.orientacion = (cst.orientacion+1)%4;
		}
		else {
			cst.orientacion = (cst.orientacion+3)%4;
		}
		it++;
	}
}



int ComportamientoJugador::interact(Action accion, int valor){
  return false;
}

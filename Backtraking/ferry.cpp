#include <iostream>
#include <string>

using namespace std;

typedef enum { BABOR, ESTRIBOR } tPosicion;
const int N = 1000;

void ferry(float longFerry, float longCars[], int n, int k, tPosicion sol[],
	float estribor, float babor, tPosicion solMejor[], int &mejorCantidad);
void ferry(float longCars[], int n);
void copiarMejorSolucion(tPosicion solMejor[], tPosicion sol[], int numCoches);
bool esSolucion(float longFerry, float estribor, float babor, float longCar);
void tratarMejorSol(tPosicion solMejor[], int k);
string enumString(tPosicion posicion);

int main(){

	float longCars[N];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> longCars[i];
	}
	ferry(longCars, n);

	return 0;
}
void tratarMejorSol(tPosicion solMejor[], int k){
	for (int i = 0; i < k; i++){
		cout << enumString(solMejor[i]) << " ";
	}
}
string enumString(tPosicion posicion){
	string cadena = "";
	switch (posicion){
	case BABOR:{ return "BABOR"; } break;
	case ESTRIBOR:{ return "ESTRIBOR"; } break;
	}
}
void ferry(float longFerry, float longCars[], int n, int k, tPosicion sol[], 
	float estribor, float babor, tPosicion solMejor[], int &mejorCantidad){

	sol[k] = BABOR;
	babor += longCars[k];
	if (babor <= longFerry){ //esValida
		if (k == n || esSolucion(longFerry, estribor, babor, longCars[k + 1])){ //esSolución
			if (k + 1 > mejorCantidad){ //¿soluciónMejor?
				mejorCantidad = k + 1;
				copiarMejorSolucion(solMejor, sol, k + 1);
				tratarMejorSol(solMejor, k+1);
			}
		}
		else {
			ferry(longFerry, longCars, n, k + 1, sol, estribor, babor, solMejor, mejorCantidad);
		}
	}
	babor -= longCars[k];
	sol[k] = ESTRIBOR;
	estribor += longCars[k];
	if (estribor <= longFerry){ //esValida
		if (k == n || esSolucion(longFerry, estribor, babor, longCars[k + 1])){ //esSolución
			if (k + 1 > mejorCantidad){ //¿soluciónMejor?
				mejorCantidad = k + 1;
				copiarMejorSolucion(solMejor, sol, k + 1);
				tratarMejorSol(solMejor, k+1);
			}
		}
		else {
			ferry(longFerry, longCars, n, k + 1, sol, estribor, babor, solMejor, mejorCantidad);
		}
	}
	estribor -= longCars[k];
	
}

bool esSolucion(float longFerry, float estribor, float babor, float longCar){
	bool ok = false;
	if (longFerry < (estribor + longCar) && longFerry < (babor + longCar)){
		ok = true;
	}
	return ok;
}
void copiarMejorSolucion(tPosicion solMejor[], tPosicion sol[], int numCoches){
	for (int i = 0; i < numCoches; i++){
		solMejor[i] = sol[i];
	}
}

void ferry(float longCars[], int n){
	float longFerry = 50;
	tPosicion sol[N], solMejor[N];
	int mejorCantidad = 0;

	return ferry(longFerry, longCars, n, 0, sol, 0, 0, solMejor, mejorCantidad);
	
}
#include <iostream>
using namespace std;

typedef struct {
	int columna;
	int fila;
} tCasilla;

const int Alto = 5;
const int Ancho = 8;

tCasilla sigDireccion(int i, tCasilla casillaAnterior);
void eda(char Tablero[Ancho][Alto]);
bool esValido(tCasilla solucion[], tCasilla casillaActual, int k,
	char Tablero[Ancho][Alto], bool marcas[Ancho][Alto]);
void eda(char Tablero[Ancho][Alto], tCasilla solucion[],
	bool marcas[Ancho][Alto], tCasilla solMejor[], int k, int & mejorSol);
void tratarMejorSol(tCasilla solMejor[], int k);
void copiarMejorSolucion(tCasilla solMejor[], tCasilla solucion[], int k);
bool esSolucion(tCasilla casilla);
void inicializaTablero(bool marcas[Ancho][Alto]);

int main() {

	char Tablero[Ancho][Alto];
	
	Tablero[0][0] = 'M';
	Tablero[0][1] = 'A';
	Tablero[0][2] = 'D';
	Tablero[0][3] = 'E';
	Tablero[0][4] = 'E';
	Tablero[1][0] = 'D';
	Tablero[1][1] = 'E';
	Tablero[1][2] = 'B';
	Tablero[1][3] = 'A';
	Tablero[1][4] = 'D';
	Tablero[2][0] = 'A';
	Tablero[2][1] = 'E';
	Tablero[2][2] = 'D';
	Tablero[2][3] = 'E';
	Tablero[2][4] = 'M';
	Tablero[3][0] = 'A';
	Tablero[3][1] = 'D';
	Tablero[3][2] = 'X';
	Tablero[3][3] = 'D';
	Tablero[3][4] = 'P';
	Tablero[4][0] = 'E';
	Tablero[4][1] = 'D';
	Tablero[4][2] = 'E';
	Tablero[4][3] = 'A';
	Tablero[4][4] = 'L';
	Tablero[5][0] = 'E';
	Tablero[5][1] = 'A';
	Tablero[5][2] = 'D';
	Tablero[5][3] = 'R';
	Tablero[5][4] = 'E';
	Tablero[6][0] = 'D';
	Tablero[6][1] = 'N';
	Tablero[6][2] = 'A';
	Tablero[6][3] = 'T';
	Tablero[6][4] = 'D';
	Tablero[7][0] = 'A';
	Tablero[7][1] = 'D';
	Tablero[7][2] = 'E';
	Tablero[7][3] = 'D';
	Tablero[7][4] = 'A';

	eda(Tablero);


	return 0;

}
void eda(char Tablero[Ancho][Alto]) {

	tCasilla solucion[Alto * Ancho]; //solucion peor
	bool marcas[Ancho][Alto];
	tCasilla solMejor[Alto * Ancho];
	int mejorSol = Alto * Ancho;
	solucion[0].columna = 0;
	solucion[0].fila = 4;
	inicializaTablero(marcas);
	eda(Tablero, solucion, marcas, solMejor, 1, mejorSol);

}
void eda(char Tablero[Ancho][Alto], tCasilla solucion[],
	bool marcas[Ancho][Alto], tCasilla solMejor[], int k, int & mejorSol) {
	for (int i = 0; i < 4; i++) {
		solucion[k] = sigDireccion(i, solucion[k - 1]); //
		if (esValido(solucion, solucion[k], k, Tablero, marcas)){
			if (k == 3 && esSolucion(solucion[k])){
				if (k + 1>mejorSol){
					mejorSol = k + 1;
					copiarMejorSolucion(solMejor, solucion, k + 1);
					tratarMejorSol(solMejor, k + 1);
				}
			}
			else{

				marcas[solucion[k].columna][solucion[k].fila] = true;
				eda(Tablero, solucion, marcas, solMejor, k + 1, mejorSol);
				marcas[solucion[k].columna][solucion[k].fila] = false;

			}
		}
	}

}
void inicializaTablero(bool marcas[Ancho][Alto]){

	for (int i = 0; i < Ancho; i++){
		for (int j = 0; j < Alto; j++){
			marcas[i][j] = false;
		}
	}
}
void tratarMejorSol(tCasilla solMejor[], int k){
	for (int i = 0; i < k; i++){
		cout << solMejor[i].columna << ", " << solMejor[i].fila << "   ";
	}
}
void copiarMejorSolucion(tCasilla solMejor[], tCasilla solucion[], int k){
	for (int i = 0; i < k; i++){
		solMejor[i] = solucion[i];
	}
}
bool esValido(tCasilla solucion[], tCasilla casillaActual, int k,
	char Tablero[Ancho][Alto], bool marcas[Ancho][Alto]) {
	bool ok = false;

	if (casillaActual.fila >= 0 && casillaActual.fila < Alto

		&& casillaActual.columna >= 0 && casillaActual.columna <Ancho) {

		if (!marcas[casillaActual.columna][casillaActual.fila]) {

			if (Tablero[solucion[k].columna][solucion[k].fila] == 'A'
				&& Tablero[solucion[k - 1].columna][solucion[k - 1].fila]
				== 'D') {

				ok = true;

			}
			else if (Tablero[solucion[k].columna][solucion[k].fila] == 'D'
				&& Tablero[solucion[k - 1].columna][solucion[k - 1].fila]
				== 'E') {

				ok = true;

			}
			else if (Tablero[solucion[k].columna][solucion[k].fila] == 'E'
				&& Tablero[solucion[k - 1].columna][solucion[k - 1].fila]
				== 'A') {

				ok = true;

			}

		}

	}
	return ok;

}

bool esSolucion(tCasilla casilla) {

	return (casilla.fila == 0 && casilla.columna == 7);

}
tCasilla sigDireccion(int i, tCasilla casillaAnterior) {

	tCasilla sigCasilla = casillaAnterior;

	switch (i) {

	case 0:
		sigCasilla.fila--;
		break;

	case 1:
		sigCasilla.columna--;
		break;

	case 2:
		sigCasilla.fila++;
		break;

	case 3:
		sigCasilla.columna++;
		break;

	}

	return sigCasilla;

}


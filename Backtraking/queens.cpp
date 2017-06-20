#include <iostream>
using namespace std;

const int N = 4;

int casilla[N][N];

void reinas(int sol[], int k, int n, int solMejor[], int  &mejorSuma, int &suma, int casilla[][N]);
void reinas(int  casilla[][N]);
bool esValida(int solucion[], int k);
bool esSolucion(int k, int n);
void copiarMejorSolucion(int sol[], int solMejor[], int k);
void tratarMejorSolucion(int solMejor[], int k);

int main(){

	reinas(casilla);

	return 0;
}


void reinas(int sol[], int k, int n, int solMejor[], int  &mejorSuma, int &suma, int casilla[][N]){

	for (int i = 0; i < n; i++){

		sol[k] = i;

		if (esValida(sol, k)){

			suma  += casilla[k][i];
		
			if (esSolucion(k, n)){

				if (suma > mejorSuma){

					mejorSuma = suma;
					copiarMejorSolucion(solMejor, sol, k + 1);
					tratarMejorSolucion(solMejor, k + 1);
				}
			}
			else {
				reinas(sol, k + 1, n, solMejor, mejorSuma, suma, casilla);
			}

		}

	}
}

bool esValida(int solucion[], int k){

	bool correcto = true;
	int i = 0;

	while(i < k && correcto){

		if ((solucion[i] == solucion[k]) || abs(solucion[k] - solucion[i]) == k - i)
			correcto = false;
		
		i++;
	}

	return correcto;
}

bool esSolucion(int k, int n){

	return k == n;
}

void copiarMejorSolucion(int sol[], int solMejor[], int k){

	for (int i = 0; i < k; i++)

		solMejor[i] = sol[i];
}

void tratarMejorSolucion(int solMejor[], int k){

	for (int i = 0; i < k; i++)

		cout << solMejor[i] << " , ";

}
void reinas(int  casilla[][N]){

	int cont = 1, mejorSuma = 0, suma = 0;
	int sol[N], solMejor[N];

	for (int i = 0; i < N; i++){

		for (int j = 0; j < N; j++)
			casilla[i][j] = cont++;
	
	}

	reinas(sol, 0, 4, solMejor, mejorSuma, suma, casilla);
}
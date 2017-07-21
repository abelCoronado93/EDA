#include <iostream>

using namespace std;

typedef enum {AZUL, BLANCO, ROJO} tColores;

void banderaHolandesa(tColores V[], int n);
void imprimirBandera(tColores V[], int n);

int main(){
	const int N = 4;
	tColores V[N];
	V[0] = ROJO; V[1] = BLANCO; V[2] = AZUL; V[3] = BLANCO;
	imprimirBandera(V, N);
	banderaHolandesa(V, 4);
	imprimirBandera(V, N);
	return 0;
}

void banderaHolandesa(tColores V[], int n){
	int contAzul = 0, contBlanco = 0, contRojo = 0;
	for (int i = 0; i < n; i++){
		if (V[i] == AZUL){ contAzul++; }
		else if (V[i] == BLANCO){ contBlanco++; }
		else { contRojo++; }
	}
	for (int i = 0; i < contAzul; i++){
		V[i] = AZUL;
	}
	for (int i = contAzul; i < contAzul+contBlanco; i++){
		V[i] = BLANCO;
	}
	for (int i = contAzul+contBlanco; i < n; i++){
		V[i] = ROJO;
	}
}

void imprimirBandera(tColores V[], int n){
	for (int i = 0; i < n; i++){
		cout << V[i] << " ";
	}
	cout << endl;
}
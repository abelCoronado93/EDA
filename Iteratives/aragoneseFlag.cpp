#include <iostream>
#include <cmath>

using namespace std;

typedef enum {ROJO, AMARILLO} tColores;

void algoritmoA(tColores V[], int n);
void algoritmoB(tColores V[], int n);
void imprimirBandera(tColores V[], int n);

int main(){
	const int N = 10;
	tColores V[N];
	V[0] = AMARILLO; V[1] = AMARILLO; V[2] = AMARILLO; V[3] = ROJO; V[4] = AMARILLO; V[5] = AMARILLO;
	V[6] = ROJO; V[7] = ROJO; V[8] = AMARILLO; V[9] = ROJO;
	imprimirBandera(V, N);
	algoritmoB(V, N);
	imprimirBandera(V, N);
	return 0;
}
//Primero rojo y luego amarillo
void algoritmoA(tColores V[], int n){ 
	int contRojo = 0, contAmarillo = 0;
	for (int i = 0; i < n; i++){
		if (V[i] == ROJO){ contRojo++; }
		else { contAmarillo++; }
	}
	for (int i = 0; i < contRojo; i++){
		V[i] = ROJO;
	}
	for (int i = contRojo; i < contRojo + contAmarillo; i++){
		V[i] = AMARILLO;
	}
}
//Posiciones impares rojo, pares amarillo
void algoritmoB(tColores V[], int n){
	int contRojo = 0, contAmarillo = 0;
	for (int i = 0; i < n; i++){
		if (V[i] == ROJO){ contRojo++; }
		else { contAmarillo++; }
	}
	int limite = (contAmarillo - contRojo), menor;
	if (limite < 0){ menor = contAmarillo; }
	else { menor = contRojo; }
	for (int i = 0; i < menor*2; i++){
		V[i] = AMARILLO;
		i++;
		V[i] = ROJO;
	}
	if (limite > 0){
		for (int j = menor * 2; j < menor * 2 + limite; j++){
			V[j] = AMARILLO;
		}
	}
	else {
		abs(limite);
		for (int j = menor * 2; j < menor * 2 + limite; j++){
			V[j] = ROJO;
		}
	}

}
void imprimirBandera(tColores V[], int n){
	for (int i = 0; i < n; i++){
		cout << V[i] << " ";
	}
	cout << endl;
}
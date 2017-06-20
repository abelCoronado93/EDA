#include <iostream>
#include <climits>

using namespace std;


const int MP = 20; // Num max de paises
const int MC = 20; // Num max de colores

void colorear(bool fronteras[][MP], int npaises, int ncolores, int colores[], 
			  int paises[], int &mejorCoste, int solucion[], int coste, int k);
void colorear(bool fronteras[][MP], int npaises, int ncolores, int colores[], 
			  int paises[], int &mejorCoste);
bool esValida(int solucion[], int k, bool fronteras[][MP]);
bool hayFrontera(bool fronteras[][MP], int k, int i);

int main() {
    int nmapas;    // num de mapas a colorear
    
    int npaises;   // num de paises del mapa actual
    int ncolores;  // num de colores para el mapa actual
    
    int paises[MP];  // superficie de cada pais en el mapa actual
    int colores[MC]; // coste para colorear una unidad de superficie usando cada color
    
    // fronteras[i][j] indica si existe frontera entre los paises i y j en el mapa
    // Es una matriz simetrica (fronteras[i][j] == fronteras[j][i])
    bool fronteras[MP][MP];
    
    // Leer numero de mapas del caso de pruebas
    cin >> nmapas;
    for (int i=0; i<nmapas; i++) {
        // Leer numero de paises y colores para el mapa actual
        cin >> npaises;
        cin >> ncolores;
        
        // Leer superficie de cada pais
        for (int j=0; j<npaises; j++)
            cin >> paises[j];
        
        // Leer coste de cada color (por unidad de superficie)
        for (int j=0; j<ncolores; j++)
            cin >> colores[j];
        
        // Leer matriz de fronteras
        for (int j=0; j<npaises; j++) {
            for (int k=0; k<npaises; k++) {
                cin >> fronteras[j][k];
            }
        }
        
        int mejorcoste = INT_MAX;
        
		colorear(fronteras, npaises, ncolores, colores, 
			  paises, mejorcoste);
        
        cout << mejorcoste << endl;
    }
    
    return 0;
}
void colorear(bool fronteras[][MP], int npaises, int ncolores, int colores[], 
			  int paises[], int &mejorCoste){

	int solucion[MP];
	
	colorear(fronteras, npaises, ncolores, colores, paises, mejorCoste, solucion, 0, 0);
}

void colorear(bool fronteras[][MP], int npaises, int ncolores, int colores[] , 
			  int paises[], int &mejorCoste, int solucion[], int coste, int k){

	for(int c = 0; c < ncolores; c++){

		solucion[k] = c;

		coste += paises[k] * colores[c];

		if(esValida(solucion, k, fronteras)){

			if(k == npaises-1){

				if(coste < mejorCoste)

					mejorCoste = coste;

			}

			else 
                colorear(fronteras, npaises, ncolores, colores, paises, mejorCoste, 
					solucion, coste, k + 1);
		}
		coste -= paises[k] * colores[c];
	}
}

bool esValida(int solucion[], int k, bool fronteras[][MP]) {

	int i = 0; bool valida = true;

	while (i < k && valida) {

		if (hayFrontera(fronteras, k, i) && solucion[k] == solucion[i])
			valida = false;

		i++;
	}
	return valida;
}

bool hayFrontera(bool fronteras[][MP], int k, int i){
	return fronteras[i][k];
}

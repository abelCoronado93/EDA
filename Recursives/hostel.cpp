#include <iostream>

using namespace std;

const int N = 1000;

int hostal(int V[], int n);
int hostal(int V[], int a, int b, int indice);

int main(){
	int num, V[N];
	cin >> num;

	while (num >= 0){
		
		for (int i = 0; i < num; i++)
			cin >> V[i];
		
		cout << hostal(V, num) << endl;

		cin >> num;
	}
	return 0;
}

int hostal(int V[], int n){

	return hostal(V, 0, n - 1, 1);
}

int hostal(int V[], int a, int b, int indice){

	int ingresos = 0;

	if (a == b)

		ingresos = indice * V[a]; /*También valdría -> ingresos = indice * V[b];*/
	
	
	if (a < b)

		ingresos = hostal(V, a + 1, b - 1, indice * 2) + (V[a] + V[b]) * indice;
	

	return ingresos;
}


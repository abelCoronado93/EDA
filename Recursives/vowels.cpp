#include <iostream>

using namespace std;

const int N = 1000;

int vocales(char V[], int n);


int main(){
	char V[N]; int n;
	cin >> n;
	while (n > 0){
		for (int i = 0; i < n; i++){
			cin >> V[i];
		}
		cout << vocales(V, n) << endl << endl;
		cin >> n;
	}
	return 0;
}

int vocales(char V[], int n){
	int numVocales = 0;
	if (n >= 0){
		if (V[n-1] == 'a' || V[n-1] == 'e' || V[n-1] == 'i' || V[n-1] == 'o' || V[n-1] == 'u'){
			numVocales = vocales(V, n-1) + 1;
		}
		else {
			numVocales = vocales(V, n-1);
		}
	}
	
	return numVocales;
}



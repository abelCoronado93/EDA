#include <iostream>

using namespace std;

int const N = 1000;

int doble(int U[], int V[], int n);
int doble(int U[], int V[], int u, int v);

int main(){
	int num, U[N], V[N];

	cin >> num;
	while (num > 0){
		for (int i = 0; i < num; i++){
			cin >> U[i];
		}
		for (int j = 0; j < num; j++){
			cin >> V[j];
		}

		cout << doble(U, V, num) << endl;

		cin >> num;
	}
	return 0;
}


int doble(int U[], int V[], int n){
	
	return doble(U, V, n, n);
}

int doble(int U[], int V[], int u, int v){

	int total = 0;

	if (u == 0)
		total = 0;

	else {
		if (U[u - 1] == V[v - 1])
			total = doble(U, V, u - 1, v) + 1;
		
		else if (U[u - 1] < V[v - 1])
			total = doble(U, V, u, v - 1);
		
		else 
			total = doble(U, V, u - 1, v);
	}
	return total;
}

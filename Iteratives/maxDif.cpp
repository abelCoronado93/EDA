#include <iostream>

using namespace std;

int maxresta(int A[], int n);

int main(){
	const int N = 1000;
	int A[N], resta;

	A[0] = 1;
	A[1] = 2;
	A[2] = 3;
	A[3] = 4;
	A[4] = 5;

	resta = maxresta(A, 4);
	cout << resta << endl;
	return 0;
}

int maxresta(int A[], int n){
	int p = A[0];
	int q = A[1];
	int aux;
	if (q > p){
		aux = p;
		p = q;
		q = aux;
	}
	for (int i = 2; i < n; i++){
		if (A[i] < q){
			q = A[i];
		}
		else if (A[i] > p){
			p = A[i];
		}
	}
	aux = p - q;
	return aux;
}
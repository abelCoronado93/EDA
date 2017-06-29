#include <iostream>

using namespace std;

const int N = 1000;

int producto(int V[], int n, int b);

int main(){
	int V[N], n;

	cin >> n;
	while (n > 0){
		for (int i = 0; i < n; i++){
			cin >> V[i];
		}
		cout << producto(V, n, 10) << endl;
		cin >> n;
	}
	return 0;
}

int producto(int V[], int n, int b){
	int total = 1;
	if (n > 0){
		if (V[n - 1] >= b){
			total = producto(V, n - 1, b) * V[n - 1];
		}
		else {
			total = producto(V, n - 1, b);
		}
	}
	return total;
}
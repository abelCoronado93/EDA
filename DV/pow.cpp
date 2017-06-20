#include <iostream>

using namespace std;

int potencia(int x, int n);

int main(){
	int n, x;

	cin >> x;
	cin >> n;

	cout << potencia(x, n) << endl;

	return 0;
}

int potencia(int x, int n){

	if (n == 0) return 1;
	if ((n % 2) != 0)
		return x * potencia(x * x, n / 2);
	else
		return potencia(x * x, n / 2);
}
	




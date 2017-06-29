#include <iostream>

using namespace std;

void dosFib(int n, int &r, int &s);
int fib(int n);

int main(){
	int n, r, s;

	cout << "Introduzca un numero";
	cin >> n;

	if (n >= 0){
		dosFib(n, r, s);
		cout << r << endl;
		cout << s << endl;
	}

	return 0;
}

int fib(int n){
	int fibonacci = 0;
	if (n == 0)
		fibonacci = 0;
	
	else if (n == 1)
		fibonacci = 1;
	
	else
		fibonacci = fib(n - 1) + fib(n - 2);

	return fibonacci;
}

void dosFib(int n, int &r, int &s){

	if (fib(n) == 0){
		r = 0;
		s = 1;
	}

	else if (fib(n) == 1){
		r = 1;
		s = fib(n + 1);
	}

	else {
		r = fib(n);
		s = fib(n + 1);
	}
}
#include <iostream>
#include <set>
#include <math.h>

using namespace std;

bool esCubifinito(int n);
int siguiente(int n);

int main(){
	int n;
	cin >> n;
	while (n != 0){
		if (esCubifinito(n))
			cout << " -> cubifinito." << endl;
		else
			cout << " -> no cubifinito." << endl;
		cin >> n;
	}
	return 0;
}

bool esCubifinito(int n){
	
	set<int> s;
	s.insert(n);
	cout << n;

	if (n != 1){
		n = siguiente(n);
		while ((n != 1) && (!s.count(n))){
			cout << " - " << n;
			s.insert(n);
			n = siguiente(n);
		}
		cout << " - " << n;
	}
	
	return n == 1;
}

int siguiente(int n){
	
	int numSig = 0, cifra;
	while (n != 0){
		cifra = n % 10;
		cifra = pow(cifra, 3);
		numSig = numSig + cifra;
		n = n / 10;
	}
	
	return numSig;
}


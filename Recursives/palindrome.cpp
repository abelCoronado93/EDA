#include <iostream>

using namespace std;

const int N = 1000;
bool palindromo(char V[], int n);

int main(){
	char V[N];
	int num;
	cin >> num;
	while (num > 0){
		for (int i = 0; i < num; i++){
			cin >> V[i];
		}
		cout << palindromo(V, num) << endl;
		cin >> num;
	}

	return 0;
}

bool palindromo(char V[], int a, int b){
	bool palind = true;
	if (a < b){
		if (V[a] == V[b])
			palind = palindromo(V, a + 1, b - 1);

		else 
			return false;
	}
	return palind;
}

bool palindromo(char V[], int n){
	return palindromo(V, 0, n-1);
}
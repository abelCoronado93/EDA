#include <iostream>

using namespace std;

int binaryToDecimal(int binary);

int main(){
	int numBinary, decimalFinal;
	cout << "Introduce numero binario: ";
	cin >> numBinary;
	decimalFinal = binaryToDecimal(numBinary);
	cout << "Equivalente decimal: " << decimalFinal << endl;

	return 0;
}

int binaryToDecimal(int binary, int p){
	int decimal = 0; int cifra = 0;
	cifra = binary % 10;
	if (binary > 0)
		decimal = (cifra * p) + binaryToDecimal(binary / 10, 2 * p);
	
	return decimal;
}

int binaryToDecimal(int binary){
	return binaryToDecimal(binary, 1);
}


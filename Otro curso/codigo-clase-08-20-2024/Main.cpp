#pragma once
#include <iostream>

using namespace std;

int main() {

	cout << "Hola mundo!!";
	char charValue = 'b';
	double b = 0.0;
	bool estoyContento = true;
	int a;

	cin >> estoyContento;

	/*if (estoyContento) {
		charValue = 'c';
	}
	else
		charValue = 'h';*/
	charValue = estoyContento ? 'c' : 'h';
	switch (charValue)
	{
	case 'z':
		//algo
		break;
	case 'h':
		//otro algo
		break;
	default:
		break;
	}

	/*int contador = 4;
	while (contador <= 5) {
		cout << "Valor del contador " << contador <<
			(contador != 5 ? ", " : ";\n");
		contador = contador + 1;
	}*/

	int contador;
	for (contador = 4; contador <= 5; contador++) {
		cout << "Valor del contador " << contador <<
			(contador != 5 ? ", " : ";\n");
		
	}

	cout << contador++ << ", ";

	cout << ++contador << endl;

	do {
		cout << "Valor del contador " << contador <<
			(contador != 5 ? ", " : ";\n");
		contador = contador + 1;
	}while (contador <= 5);

	cout << "el charValue es... " << charValue << endl;
	cin >> a;

	//funciones
	//.h
	//struct & union 
	return 0;
}
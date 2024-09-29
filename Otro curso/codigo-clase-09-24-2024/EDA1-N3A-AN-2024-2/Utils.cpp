#include "Utils.h"
#include <iostream>

using namespace std;

union testUnion {
	int edad;
	double valor;
	bool esHumano;
};

struct testStruct {
	int edad;
	bool esHumano;
};

int dividir(int div, int divis) {
	return div / divis;
}

int funcionPrueba() {
	int contador;
	for (contador = 4; contador <= 5; contador++) {
		cout << "Valor del contador " << contador <<
			(contador != 5 ? ", " : ";\n");

	}
	return contador;
}

void codigoPrimeraClase() {

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

	int contador = funcionPrueba();


	cout << contador++ << ", ";

	cout << ++contador << endl;

	do {
		cout << "Valor del contador " << contador <<
			(contador != 5 ? ", " : ";\n");
		contador = contador + 1;
	} while (contador <= 5);

	cout << "el charValue es... " << charValue << endl;
	cin >> a;

	//funciones
	//.h
	//struct & union 
	testStruct unStruct;
	unStruct.edad = 5;
	unStruct.esHumano = true;

	cout << "Edad: " << unStruct.edad << ", Es Humano"
		<< (unStruct.esHumano ? "Si" : "No") << endl;
}
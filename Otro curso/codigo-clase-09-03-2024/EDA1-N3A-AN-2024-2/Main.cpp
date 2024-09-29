#pragma once
#include "Utils.h"
#include "PunterosYVectores.h"
#include <iostream>
#include "Islas.h"

using namespace std;

int largo(char* palabra) {
	int index = 0;
	while (palabra[index] != '\0')
		index++;

	return index;
}

//PRE: palabra no es vacia
char* copia(char* palabra) {
	char* nuevo = new char[largo(palabra) + 1];
	int idx;
	for (idx = 0; palabra[idx] != '\0'; idx++) {
		nuevo[idx] = palabra[idx];
	}
	nuevo[idx] = '\0';
	return nuevo;
}

//PRE se recibe un char* con letras mayusculas
char* copiaYMinuscula(char* palabra) {
	char* nuevo = new char[largo(palabra) + 1];
	int idx;
	for (idx = 0; palabra[idx] != '\0'; idx++) {
		nuevo[idx] = palabra[idx]+32;
	}
	nuevo[idx] = '\0';
	return nuevo;
}

void generarNumeros(int num) {
	if (num == 0) return;
	cout << num << endl;
	generarNumeros(--num);
	cout << num << endl;
}

int main() {
	//codigoPrimeraClase();
	//ejecutarPruebas();
	char* palabra = new char[5] {'H', 'O', 'L', 'A'};
	palabra[4] = '\0';

	cout << palabra << endl;
	cout << copia(palabra) << endl;
	cout << copiaYMinuscula(palabra) << endl;

	generarNumeros(2);

	//islas();
	
	return 0;
}
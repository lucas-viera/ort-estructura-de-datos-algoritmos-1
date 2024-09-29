#include "PunterosYVectores.h"
#include <iostream>
#define LARGO_ARRAY 3
using namespace std;

int* crearVector(int largo) {
	int* vec;
	vec = new int[largo];
	for (int i = 0; i < largo; i++) {
		vec[i] = i * 2;
	}

	return vec;
}

void ejecutarPruebas() {
	//Punteros
	char charValue = 'b';
	double b = 4.1;
	bool estoyContento = true;
	cout << estoyContento << " " << b << " " << charValue << " " << endl;

	cout << &estoyContento << " " << &b << " " << &charValue << " " << endl;

	char* ptr = &charValue;
	cout << endl;
	cout << &charValue << " " << endl;
	cout << endl;
	cout << ptr << " " << endl;
	cout << *ptr << " " << endl;

	ptr = NULL;
	//Vectores
	int primeraForma[] = { 1 ,2, 3 };
	int segundaForma[3] = { 1 ,2, 3 };
	int terceraForma[LARGO_ARRAY];
	terceraForma[0] = 1;
	terceraForma[1] = 2;
	terceraForma[2] = 3;
	const int valor = 5;
	int caso4[valor];

	int largo;
	cin >> largo;

	int* vec = crearVector(largo);

	cout << vec[1] << endl;
	cout << *(vec + 1) << endl;

	delete[] vec;
	//Otras operaciones
}
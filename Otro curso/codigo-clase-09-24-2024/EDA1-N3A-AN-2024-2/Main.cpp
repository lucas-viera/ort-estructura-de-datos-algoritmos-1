#pragma once
#include <iostream>
#include "Utils.h"
#include "PunterosYVectores.h"
#include "Islas.h"
#include "StringEjercicios.h"
#include "ListasSimplementeEncadenadas.h"

using namespace std;

struct NodoAB {
	int dato;
	NodoAB* izq;
	NodoAB* der;
};

/*
		1
	   /  \
	  4    3
			\
			 5
*/
int altura(NodoAB* r) {
	if (!r) return 0;

	int maxAlturaIzq = altura(r->izq);
	int maxAlturaDer = altura(r->der);

	return 1 + (maxAlturaIzq > maxAlturaDer ? maxAlturaIzq : maxAlturaDer);
}

int cantNodos(NodoAB* r) {
	if (!r) return 0;

	return 1 + cantNodos(r->izq) + cantNodos(r->der);
}

int cantHojas(NodoAB* r) {
	if (!r) return 0;

	if (!r->izq && !r->der) return 1;

	return cantHojas(r->izq) + cantHojas(r->der);
}

NodoAB* espejoFunc(NodoAB* r) {
	if (!r) return NULL;

	NodoAB* espejo = new NodoAB;
	espejo->dato = r->dato;
	espejo->izq = espejoFunc(r->der);
	espejo->der = espejoFunc(r->izq);

	return espejo;
}

//Pre-order
void imprimirPreOrder(NodoAB* r) {
	if (!r) return;
	cout << r->dato << endl;
	imprimirPreOrder(r->izq);
	imprimirPreOrder(r->der);
}

//In-order
void imprimirInOrder(NodoAB* r) {
	if (!r) return;
	imprimirInOrder(r->izq);
	cout << r->dato << endl;
	imprimirInOrder(r->der);
}

//Pos-order
void imprimirPosOrder(NodoAB* r) {
	if (!r) return;
	imprimirPosOrder(r->izq);
	imprimirPosOrder(r->der);
	cout << r->dato << endl;
}

//Pre: r != NULL
int obtenerMaximo(NodoAB* r) {
	int dato = r->dato;

	if (!r->izq && !r->der) {
		return dato;
	}
	else if (r->izq && !r->der) {
		int maxIzq = obtenerMaximo(r->izq);
		return dato > maxIzq ? dato : maxIzq;
	}
	else if (!r->izq && r->der) {
		int maxDer = obtenerMaximo(r->der);
		return dato > maxDer ? dato : maxDer;
	}
	else {
		int maxIzq = obtenerMaximo(r->izq);
		int maxDer = obtenerMaximo(r->der);

		int maxHijos = maxIzq > maxDer ? maxIzq : maxDer;

		return dato > maxHijos ? dato : maxHijos;
	}
}

void obtenerInfoDelArbol(NodoAB* r) {
	cout << "ALTURA: " << altura(r) << endl;
	cout << "Cantidad de hojas: " << cantHojas(r) << endl;
	cout << "Cantidad de nodos: " << cantNodos(r) << endl;

	imprimirInOrder(r);

	cout << "ESPEJO: " << endl;
	imprimirInOrder(espejoFunc(r));

	cout << "MAXIMO: " << obtenerMaximo(r) << endl;
}

// ABB ~ Arbol binario de busqueda 
// la estructura es la misma que el AB.
// Para todo nodo, todos los elementos que 
// se encuentran a la izquierda van a ser <= y
// todos los elementos que se encuentran 
// a la derecha van a ser >=.

// Nota: Normalmente el ABB no tiene repetidos,
// pero a niveles practicos puede tenerlos :D 

//Pre: r es un ABB
void agregarEnABB(NodoAB*& r, int valor) {
	if (!r) {
		NodoAB* nuevo = new NodoAB;
		nuevo->dato = valor;
		nuevo->izq = NULL;
		nuevo->der = NULL;
		r = nuevo;
	}
	else if (r->dato >= valor) {
		agregarEnABB(r->izq, valor);
	}
	else { // r->dato < valor
		agregarEnABB(r->der, valor);
	}
}

//Pre: r != NULL
int obtenerMaximoABB(NodoAB* r) {
	//TODO
	return 0;
}

//Pre: r es un ABB 
void agregarNDatosAlABB(NodoAB*& r, int n) {
	for (int i = 0; i < n; i++) {
		int nuevoDato;
		cin >> nuevoDato;
		agregarEnABB(r, nuevoDato);
	}
}

int main() {
	//codigoPrimeraClase();
	//ejecutarPruebas();
	//ejerciciosString();
	//islas();
	//ejerciciosListasSimplementeEncadenadas();
	/*
		1
	   /  \
	  4    3
			\
			 5
	*/
	NodoAB* rEjemplo = new NodoAB;
	rEjemplo->dato = 1;

	rEjemplo->izq = new NodoAB;
	rEjemplo->izq->dato = 4;
	rEjemplo->izq->izq = NULL;
	rEjemplo->izq->der = NULL;

	rEjemplo->der = new NodoAB;
	rEjemplo->der->dato = 3;
	rEjemplo->der->izq = NULL;
	rEjemplo->der->der = new NodoAB;

	rEjemplo->der->der->dato = 5;
	rEjemplo->der->der->izq = NULL;
	rEjemplo->der->der->der = NULL;

	obtenerInfoDelArbol(rEjemplo);

	cout << "EJEMPLO ABB: " << endl;
	NodoAB* rEjemploABB = NULL;
	agregarNDatosAlABB(rEjemploABB, 5);

	obtenerInfoDelArbol(rEjemploABB);
	/* ejemplo insertado en clase
		5
	   /  \
	  1    20
	 /		\
	0		 90
	*/

	return 0;
}
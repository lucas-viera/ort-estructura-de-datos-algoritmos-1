#pragma once
#include <iostream>
#include "Utils.h"
#include "PunterosYVectores.h"
#include "Islas.h"
#include "StringEjercicios.h"

using namespace std;

struct NodoListaInt {
	int dato;
	NodoListaInt* sig;
};


void agregarPpio(NodoListaInt*& lista, int nuevoDato) {
	NodoListaInt* nuevo = new NodoListaInt;
	nuevo->dato = nuevoDato;
	nuevo->sig = lista;
	lista = nuevo;
}

void imprimirListaRec(NodoListaInt* lista) {
	if (!lista) {
		cout << "NULL" << endl;
	}
	else {
		cout << lista->dato << " -> ";
		imprimirListaRec(lista->sig);
	}
}

void imprimirLista(NodoListaInt* lista) {
	while (lista) {
		cout << lista->dato << " -> ";
		lista = lista->sig;
	}
	cout << "NULL" << endl;
}

void agregarFinRec(NodoListaInt*& l, int dato) {
	if (!l) {
		NodoListaInt* nuevo = new NodoListaInt;
		nuevo->dato = dato;
		nuevo->sig = NULL;
		l = nuevo;
	}
	else {
		agregarFinRec(l->sig, dato);
	}
}

void agregarFin(NodoListaInt*& l, int dato) {
	if (!l) {
		NodoListaInt* nuevo = new NodoListaInt;
		nuevo->dato = dato;
		nuevo->sig = NULL;
		l = nuevo;
	}
	else {
		NodoListaInt* aux = l;

		while (aux->sig) {
			aux = aux->sig;
		}
		NodoListaInt* nuevo = new NodoListaInt;
		nuevo->dato = dato;
		nuevo->sig = NULL;
		aux->sig = nuevo;
	}
}

//PRE: recibe una lista ordenada de forma asc
void agregarOrdenadoRec(NodoListaInt*& l, int dato) {
	/*if (!l) {
		NodoListaInt* nuevo = new NodoListaInt;
		nuevo->dato = dato;
		nuevo->sig = NULL;
		l = nuevo;
	}
	else if (l->dato > dato) {
		NodoListaInt* nuevo = new NodoListaInt;
		nuevo->dato = dato;
		nuevo->sig = l;
		l = nuevo;
	}
	else {
		agregarOrdenadoRec(l->sig, dato);
	}*/
	if (!l || l->dato > dato) {
		NodoListaInt* nuevo = new NodoListaInt;
		nuevo->dato = dato;
		nuevo->sig = l;
		l = nuevo;
	}
	else {
		agregarOrdenadoRec(l->sig, dato);
	}
}

void agregarOrd(NodoListaInt*& l, int dato) {
	if (!l || l->dato > dato) {
		NodoListaInt* nuevo = new NodoListaInt;
		nuevo->dato = dato;
		nuevo->sig = l;
		l = nuevo;
	}
	else {
		NodoListaInt* aux = l;

		while (aux->sig && l->dato < dato){
			aux = aux->sig;
		}
		NodoListaInt* nuevo = new NodoListaInt;
		nuevo->dato = dato;
		nuevo->sig = aux->sig;
		aux->sig = nuevo;
	}
}

void agregarNDatosALaLista(NodoListaInt*& lista, int n) {
	for (int i = 0; i < n; i++) {
		int nuevoDato;
		cin >> nuevoDato;
		agregarOrd(lista, nuevoDato);
	}
}

//PRE: l != NULL
void borrarPpio(NodoListaInt*& l) {
	NodoListaInt* borro = l;
	l = l->sig;
	delete borro;
}

//PRE: l != NULL
void borrarFin(NodoListaInt*& l) {
	if (!l->sig) { //l->sig == NULL 
		NodoListaInt* borro = l;
		l = l->sig;
		delete borro;
	}
	else {
		NodoListaInt* aux = l;

		while (aux->sig->sig) {
			aux = aux->sig;
		}

		NodoListaInt* borro = aux->sig;
		aux->sig = aux->sig->sig;
		delete borro;
	}
}

void borrarFinRec(NodoListaInt*& l) {
	if (!l->sig) { //l->sig == NULL 
		NodoListaInt* borro = l;
		l = l->sig;
		delete borro;
	}
	else {
		borrarFinRec(l->sig);
	}
}

void vaciar(NodoListaInt*& l) {
	while (l) {
		borrarFinRec(l);
	}
}

void obtenerPositivosRec(NodoListaInt* l, NodoListaInt*& nueva) {
	if(!l){
		return;
	}
	else {
		if (l->dato > 0) agregarOrd(nueva, l->dato);
		obtenerPositivosRec(l->sig, nueva);
	}
}

NodoListaInt* obtenerPositivosRecSinOrden(NodoListaInt* l) {
	if (!l) {
		return NULL;
	}
	else {
		if (l->dato > 0) {
			NodoListaInt* nuevo = new NodoListaInt;
			nuevo->dato = l->dato;
			nuevo->sig = obtenerPositivosRecSinOrden(l->sig);
			return nuevo;
		}
		else
			return obtenerPositivosRecSinOrden(l->sig);
	}
}

NodoListaInt* obtenerPositivos(NodoListaInt* l) {
	/*NodoListaInt* nueva = NULL;
	obtenerPositivosRec(l, nueva);
	return nueva;*/
	NodoListaInt* nueva = NULL;
	while (l) {
		if (l->dato > 0) agregarOrd(nueva, l->dato);
		l = l->sig;
	}
	return nueva;
}

void concatRec(NodoListaInt*& l1, NodoListaInt* l2) {
	if (!l1) {
		l1 = l2;
	}
	else {
		concatRec(l1->sig, l2);
	}
}

int main() {
	//codigoPrimeraClase();
	//ejecutarPruebas();
	//ejerciciosString();
	//islas();
	NodoListaInt* lista = NULL;
	agregarNDatosALaLista(lista, 4);
	imprimirLista(lista);
	imprimirLista(obtenerPositivos(lista));
	cout << (lista ? "TIENE DATOS" : "ESTA VACIA") << endl;
	vaciar(lista);
	imprimirLista(lista);
	cout << (lista ? "TIENE DATOS" : "ESTA VACIA") << endl;



	return 0;
}
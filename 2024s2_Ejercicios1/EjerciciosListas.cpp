#include "EjerciciosListas.h"

// INICIO SECCIÓN FUNCIONES AUXILIARES

/*
PRE: recibe una lista y un entero
POS: crea un nodo y apendea el nuevo nodo al comienzo de la lista. 
	Modifica el puntero a la lista original
*/
void agregarAlInicio(NodoLista*& l, int x) {
	NodoLista* nuevoNodo = new NodoLista;
	nuevoNodo->dato = x;
	nuevoNodo->sig = l;
	l = nuevoNodo;
}

/*
PRE:
POS:
*/
int cantNodos(NodoLista* l) {
	int cant = 0;
	while (l->sig != NULL) {
		cant++;
		l = l->sig;
	}
	return cant+1;
}

/*
PRE:
POS:
*/
NodoLista* copiarLista(NodoLista* l) {
	if (l == NULL){
		return NULL;
	}
	// primer nodo de la lista copiada
	NodoLista* nuevaLista = new NodoLista;
	nuevaLista->dato = l->dato;
	nuevaLista->sig = NULL;			//puede ser innecesario

	// Cursor para recorrer l original y la lista copiada
	NodoLista* cursor = l->sig;
	NodoLista* auxNueva = nuevaLista;

	while (cursor != NULL) {
		//nodo nuevo par anexar a la copia
		NodoLista* nodoAux = new NodoLista;
		nodoAux->dato = cursor->dato;
		nodoAux->sig = NULL;

		auxNueva->sig = nodoAux;	//anexo nodo nuevo
		//avanzar 
		auxNueva = nodoAux;			//lista aux apunta a nodo nuevo
		cursor = cursor->sig;		//cursor avanza
	}

	return nuevaLista;
}

// FIN SECCIÓN FUNCIONES AUXILIARES



NodoLista* invertirParcial(NodoLista* l) {
	if (l == NULL || l->sig == NULL) {
		return NULL;
	}

	NodoLista* nuevaLista = NULL;
	NodoLista* cursor = l;

	while (cursor->sig->sig != NULL) {		// Hasta el penúltimo elemento
		agregarAlInicio(nuevaLista, cursor->dato);
		cursor = cursor->sig;
	}

	agregarAlInicio(nuevaLista, cursor->dato); // Penúltimo elemento agregado
	return nuevaLista;
}

void eliminarNesimoDesdeElFinal(NodoLista*& lista, int &n) 
{
	// IMPLEMENTAR SOLUCION (mas dificil)
}

NodoLista* listaOrdenadaInsertionSort(NodoLista* l) 
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

void listaOrdenadaSelectionSort(NodoLista*& l)
{
	// IMPLEMENTAR SOLUCION
}

NodoLista* intercalarIter(NodoLista* l1, NodoLista* l2)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

NodoLista* intercalarRec(NodoLista* l1, NodoLista* l2)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

NodoLista* insComFin(NodoLista* l, int x)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

NodoLista* exor(NodoLista* l1, NodoLista* l2)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

void eliminarDuplicadosListaOrdenadaDos(NodoLista*& l) 
{
	// IMPLEMENTAR SOLUCION
}

bool palindromo(NodoLista* l)
{
	// IMPLEMENTAR SOLUCION
	return false;
}

void eliminarSecuencia(NodoLista* &l, NodoLista* secuencia) 
{
	// IMPLEMENTAR SOLUCION
}

void moverNodo(NodoLista* &lista, unsigned int inicial, unsigned int final)
{
	// IMPLEMENTAR SOLUCION
}

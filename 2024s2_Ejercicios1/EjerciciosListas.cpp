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
void agregarAlFinal(NodoLista*& l, int x) {
	NodoLista* nuevoNodo = new NodoLista(x);
	if (l == NULL) {
		l = nuevoNodo;
	}
	else {
		NodoLista* cursor = l;
		while (cursor->sig != NULL) {	//busqueda del ultimo nodo
			cursor = cursor->sig;
		}
		cursor->sig = nuevoNodo;
	}
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

/*
PRE: recibe una lista
POS: elimina el ultimo elemento de la lista real (comparte memoria)
*/
void eliminarAlFinal(NodoLista*& l) {
	if (!l->sig) {						//caso lista 1 solo elemento
		NodoLista* aEliminar = l;
		l = l->sig;
		delete aEliminar;
	}
	else {
		NodoLista* cursor = l;
		while (cursor->sig->sig) {
			cursor = cursor->sig;
		}
		NodoLista* aEliminar = cursor->sig;
		cursor->sig = cursor->sig->sig; //se puede apuntar a NULL tambien
		delete aEliminar;
	}
}

/*
PRE: recibe una lista y dos nodos A y B de la misma lista
POS: actualiza ambos punteros de forma A quede apuntando al B->sig 
     y B quede apuntando a A->sig.
	 A su vez, el nodo que apuntaba a A, pasa a apuntar a B 
	 y el nodo que apuntaba a B, pasa a apuntar a A
*/
void intercambiarNodos(NodoLista *& lista, NodoLista*& nodoA, NodoLista*& nodoB) {
	if (lista == NULL || nodoA == nodoB) {
		return;
	}
	// Si alguno de los nodos es la cabeza de la lista, actualizamos 'lista' después
	NodoLista* prevA = NULL;
	NodoLista* prevB = NULL;
	NodoLista* cursorAux = lista;

	if (lista == nodoA) {			// Caso nodoA esta al inicio
		prevA = NULL;
	}
	else if (lista == nodoB) {		// Caso nodoB esta al inicio
		prevB = NULL;
	}
	else {
		while (cursorAux != NULL) {		//determinacion para nodos anteriores a A y B
			if (cursorAux->sig == nodoA) {
				prevA = cursorAux;
			}
			if (cursorAux->sig == nodoB) {
				prevB = cursorAux;
			}
			cursorAux = cursorAux->sig;
		}
	}
	// Intercambio de siguientes entre A y B
	NodoLista* sigAux = nodoA->sig;
	nodoA->sig = nodoB->sig;
	nodoB->sig = sigAux;

	// Actualizar punteros de los anteriores a A y B
	if (prevA != NULL) {
		prevA->sig = nodoB;
	}
	else {
		lista = nodoB; // nodoB llevado al inicio de la lista
	}

	if (prevB != NULL) {
		prevB->sig = nodoA;
	}
	else {
		lista = nodoA; // nodoA llevado al inicio de la lista
	}

	// Actualizar los punteros nodoA y nodoB
	NodoLista* temp = nodoA;
	nodoA = nodoB;
	nodoB = temp;
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

void eliminarNesimoDesdeElFinal(NodoLista*& lista, int &n) {
	// TODO

}

NodoLista* listaOrdenadaInsertionSort(NodoLista* l) {
	if (l == NULL) {
		return NULL;
	}
	if (l->sig == NULL) {
		NodoLista* lista = copiarLista(l);
		return lista;
	}

	NodoLista* ordenada = NULL;
	NodoLista* cursor = l;

	while (cursor != NULL) {
		NodoLista* nuevoNodo = new NodoLista;
		nuevoNodo->dato = cursor->dato;
		nuevoNodo->sig = NULL;

		if (ordenada == NULL || nuevoNodo->dato <= ordenada->dato) { //condicion de orden invertido, se inserta nodoNuevo "al inicio"
			nuevoNodo->sig = ordenada;
			ordenada = nuevoNodo; //asignamos null de null
		}
		else {
			NodoLista* ordenadaAux = ordenada;
			while (ordenadaAux->sig != NULL && ordenadaAux->sig->dato < nuevoNodo->dato) {	//condicion para insertar nuevoNodo
				ordenadaAux = ordenadaAux->sig;
			}
			nuevoNodo->sig = ordenadaAux->sig;
			ordenadaAux->sig = nuevoNodo;
		}
		cursor = cursor->sig;
	}
	return ordenada;
}


	void listaOrdenadaSelectionSort(NodoLista*& l) {
	if (l == NULL || l->sig == NULL) {				//caso lista vacia o con 1 solo elemento
		return;
	}
	NodoLista* cursor = l;

	while (cursor != NULL) {						//iteracion para comparar cursor sus siguientes
		NodoLista* nodoMin = cursor;
		NodoLista* movil = cursor->sig;
		while (movil != NULL) {
			if (movil->dato < nodoMin->dato) {
				nodoMin = movil;					//reemplazo por valor menor
			}
			movil = movil->sig;						//avance puntero
		}

		if (nodoMin != cursor) {					//intercambio de valores
			int aux = cursor->dato;
			cursor->dato = nodoMin->dato;
			nodoMin->dato = aux;
		}
		cursor = cursor->sig;						//avance cursor
	}
}

NodoLista* intercalarIter(NodoLista* l1, NodoLista* l2) {
	if (l1 == NULL && l2 == NULL) {
		return NULL;
	}
	if (l1 == NULL) {
		return copiarLista(l2);
	}
	if (l2 == NULL) {
		return copiarLista(l1);
	}
	
	NodoLista* ordenada = NULL;					//lista a retornar
	NodoLista* finOrd = NULL;					//cursor al final de lista ordenada
	NodoLista* cursorL1 = l1;
	NodoLista* cursorL2 = l2;
	while (cursorL1 != NULL && cursorL2 != NULL) {
		NodoLista* nuevoNodo = new NodoLista;
		nuevoNodo->sig = NULL;
		if (cursorL1->dato > cursorL2->dato) {			//insertar elem l2 primero
			nuevoNodo->dato = cursorL2->dato;
			cursorL2 = cursorL2->sig;
		}
		else {											//insertar elem l1 primero
			nuevoNodo->dato = cursorL1->dato;
			cursorL1 = cursorL1->sig;
		}

		if (ordenada == NULL) {
			ordenada = nuevoNodo;
			finOrd = nuevoNodo;
		}
		else {
			finOrd->sig = nuevoNodo;
			finOrd = nuevoNodo;
		}
	}

	//caso l1 mas largo que l2, se inserta el remanente de l1
	while (cursorL1 != NULL) {
		NodoLista* nuevoNodo = new NodoLista;
		nuevoNodo->dato = cursorL1->dato;
		nuevoNodo->sig = NULL;

		if (ordenada == NULL) {
			ordenada = nuevoNodo;
			finOrd = nuevoNodo;
		}
		else {
			finOrd->sig = nuevoNodo;
			finOrd = nuevoNodo;
		}
		cursorL1 = cursorL1->sig;
	}

	//caso l2 mas largo l1, se inserta el remanente de l2
	while (cursorL2 != NULL) {
		NodoLista* nuevoNodo = new NodoLista;
		nuevoNodo->dato = cursorL2->dato;
		nuevoNodo->sig = NULL;

		if (ordenada == NULL) {
			ordenada = nuevoNodo;
			finOrd = nuevoNodo;
		}
		else {
			finOrd->sig = nuevoNodo;
			finOrd = nuevoNodo;
		}
		cursorL2 = cursorL2->sig;
	}

	return ordenada;
}

NodoLista* intercalarRec(NodoLista* l1, NodoLista* l2) {
	if (l1 == NULL && l2 == NULL) {
		return NULL;
	}
	if (l1 == NULL) {
		return copiarLista(l2);
	}
	if (l2 == NULL) {
		return copiarLista(l1);
	}
	NodoLista* nodoNuevo = new NodoLista;
	if (l1->dato > l2->dato) {					//condicion para insertar elem de l2
		nodoNuevo->dato = l2->dato;
		nodoNuevo->sig = intercalarRec(l1, l2->sig);
	}
	else {										//condicion para insertar elem de l1
		nodoNuevo->dato = l1->dato;
		nodoNuevo->sig = intercalarRec(l1->sig, l2);
	}
	return nodoNuevo;
}

NodoLista* insComFin(NodoLista* l, int x)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

NodoLista* exor(NodoLista* l1, NodoLista* l2){
	NodoLista* ordenada = NULL;					//lista a retornar
	NodoLista* finOrd = NULL;					//cursor al final de lista ordenada
	NodoLista* cursorL1 = l1;
	NodoLista* cursorL2 = l2;
	
	while (cursorL1 != NULL || cursorL2 != NULL) {
		int dato;
		bool valido = false;

		//caso insertar dato de L1
		if (cursorL1 != NULL && (cursorL2 == NULL || cursorL1->dato < cursorL2->dato)) {
			dato = cursorL1->dato;
			valido = true;

			//avanzar cursorL1 para evitar repetidos
			int aux = cursorL1->dato;
			while (cursorL1 != NULL && cursorL1->dato == aux) {
				cursorL1 = cursorL1->sig;
			}
		}
		//caso insertar dato de L2
		else if (cursorL2 != NULL && (cursorL1 == NULL || cursorL2->dato < cursorL1->dato)) {
			dato = cursorL2->dato;
			valido = true;
			
			//avanzar cursorL2 para evitar repetidos
			int aux = cursorL2->dato;
			while (cursorL2 != NULL && cursorL2->dato == aux) {
				cursorL2 = cursorL2->sig;
			}
		}
		//el valor "vigente" es el mismo en ambas listas, se deben mover ambos cursores
		else {	
			int aux = cursorL1->dato;
			while (cursorL1 != NULL && cursorL1->dato == aux) {
				cursorL1 = cursorL1->sig;
			}
			while (cursorL2 != NULL && cursorL2->dato == aux) {
				cursorL2 = cursorL2->sig;
			}
			valido = false;
		}
		if (valido) {
			NodoLista* nuevoNodo = new NodoLista(dato);
			nuevoNodo->sig = NULL;

			if (ordenada == NULL) {		//caso lista vacia
				ordenada = nuevoNodo;
				finOrd = nuevoNodo;
			}
			else {						//caso lista no vacia
				finOrd->sig = nuevoNodo;
				finOrd = nuevoNodo;
			}
		}
	}
	return ordenada;
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

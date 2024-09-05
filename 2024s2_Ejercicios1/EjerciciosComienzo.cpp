#include "EjerciciosComienzo.h"

// INICIO SECCIÓN FUNCIONES AUXILIARES

//TODO: agregar PRE y POST
int maxComDivisor(int a, int b) {
	int num1 = max(a, b);
	int num2 = min(a, b);
	int res;
	do {
		res = num2;
		num2 = num1 % num2;
		num1 = res;

	} while (num2 != 0);
	return res;
}

/*
PRE: Recibe un vector de enteros y la cantidad de elementos del mismo
POST: Devuelve el vector con sus posiciones incializadas en 0
*/
int* inicializarListaEnteros(int* lista, int largo) {
	for (int i = 0; i < largo; i++) {
		lista[i] = 0;
	}
	return lista;
}

/*
PRE: Recibe un vector de bool y la cantidad de elementos del mismo
POST: Devuelve el vector con sus posiciones incializadas en false
*/
bool* inicializarListaBool(bool* lista, int largo) {
	for (int i = 0; i < largo; i++) {
		lista[i] = false;
	}
	return lista;
}

// FIN SECCIÓN FUNCIONES AUXILIARES

int suma(int a, int b) {
    return a + b;
}

void tablaDel(unsigned int tablaDel, unsigned int desde, unsigned int hasta) {
	for (int i = desde; i <= hasta; i++) {
		cout << i << "*" << tablaDel << "=" << i * tablaDel;
		if (i != hasta) {
			cout << ";";
		}
	}
}



void simplificar(int n, int d) {
	if (n != 0) {
		int mcd = maxComDivisor(n, d);
		n = n / mcd;
		d = d / mcd;
	}
	if (d < 0) {
		n = -n;
		d = -d;
	}
	
	cout << n << "/" << d;
}


int ocurrencias123Repetidos(int* vector, int largo) {
	int contador = 0;
	bool* flags = new bool[4];
	flags = inicializarListaBool(flags, 4);

	for (int i = 0; i < largo; i++) {
		if (vector[i] == 1 && !flags[2]) {
			flags[1] = true;
		}
		else if (vector[i] == 2 && flags[1] && !flags[3]) {
			flags[2] = true;
		}
		else if (vector[i] == 3 && flags [2]) {
			flags[3] = true;
		}
		else {
			flags = inicializarListaBool(flags, 4);
		}

		if (flags[1] && flags[2] && flags[3]) {
			contador++;
			flags = inicializarListaBool(flags, 4);
		}
	}
	return contador;
}

int maximoNumero(unsigned int n) {
	int maximo = INT_MIN;
	int* numeros = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> numeros[i];
	}
	for (int i = 0; i < n; i++) {
		if (maximo < numeros[i]) {
			maximo = numeros[i];
		}
	}
    return maximo;
}

void ordenarVecInt(int *vec, int largoVec) {
	
	

	
}

int* intercalarVector(int* v1, int* v2, int l1, int l2){
	// IMPLEMENTAR SOLUCION
	return NULL;
}

bool subconjuntoVector(int* v1, int* v2, int l1, int l2)
{
	// IMPLEMENTAR SOLUCION
	return false;
}

char* invertirCase(char* str)
{
	// IMPLEMENTAR SOLUCION
	//hacer un new, reservar memoria y retornar el char*
	return NULL;
}

int islas(char** mapa, int col, int fil){
	// IMPLEMENTAR SOLUCION
    return 0;
}

unsigned int ocurrenciasSubstring(char **vecStr, int largoVecStr, char *substr)
{
	// IMPLEMENTAR SOLUCION
    return 0;
}

char **ordenarVecStrings(char **vecStr, int largoVecStr)
{
	// IMPLEMENTAR SOLUCION
    return NULL;
}

char** splitStr(char* str, char separador, int &largoRet)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

void ordenarVecIntMergeSort(int* vector, int largo) 
{
	// IMPLEMENTAR SOLUCION
}

#include "EjerciciosComienzo.h"

// INICIO SECCIÓN FUNCIONES AUXILIARES

//TODO: agregar PRE y POS
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
POS: Devuelve el vector con sus posiciones incializadas en 0
*/
int* inicializarListaEnteros(int* lista, int largo) {
	for (int i = 0; i < largo; i++) {
		lista[i] = 0;
	}
	return lista;
}

/*
PRE: Recibe un array de bool y la cantidad de elementos del mismo
POS: Devuelve el vector con sus posiciones incializadas en false
*/
bool* inicializarListaBool(bool* lista, int largo) {
	for (int i = 0; i < largo; i++) {
		lista[i] = false;
	}
	return lista;
}

/*
* PRE: Recibe un array de enteros, la cantidad de elementos y los indices a intercambiar
* POS: La lista L tendrá invertidos los dos valores en los indices recibidos
*/
void Intercambiar(int* l, int n, int i, int j) {
	int aux = l[i];
	l[i] = l[j];
	l[j] = aux;
}

/*
* PRE:
* POS:
*/
bool elementoPertenece(int* l, int largo, int elem) {
	int i = 0;
	while (i < largo) {
		if (l[i] == elem) {
			return true;
		}
		i++;
	}
	return false;
}

/*
PRE:
POS:
*/
bool caracterEsMinuscula(char c) {
	return (c >= 'a' && c <= 'z');
}

/*
PRE:
POS:
*/
bool caracterEsMayuscula(char c) {
	return (c >= 'A' && c <= 'Z');
}

/*
PRE:
POS:
*/
char convertirAMinuscula(char c) {
	return c + ('a' - 'A');
}

/*
PRE:
POS:
*/
char convertirAMayuscula(char c) {
	return c - ('a' - 'A');
}

/*
PRE:
POS:
*/
int largoString(char* str) {
	int largo = 0;
	while (str[largo] != '\0') {
		largo++;
	}
	return largo;
}

/*
PRE: recibe 2 char
POS: devuelve -1 si el char a está antes que b en la tabla ASCII, +1 si está después o 0 si a==b
*/
int compararChar(char a, char b) {
	if (a < b) return -1;
	if (a > b) return 1;
	return 0;	
}

/*
PRE: recibe 2 string str1 str2
POS: devuelve -1 si str1 está antes que str2, +1 si está después o 0 si str1==str2
*/
int compararString(char* str1, char* str2) {
	int i = 0;
	if (str1 == NULL || str2 == NULL) return 0;

	while (str1[i] != '\0' && str2[i] != '\0') {
		int result = compararChar(str1[i], str2[i]);
		if (result != 0) {
			return result;
		}
		i++;
	}
	// Escenarios para asegurar fin de la iteracion
	if (str1[i] == '\0' && str2[i] != '\0') return -1;  // str1 más corto, va antes
	if (str1[i] != '\0' && str2[i] == '\0') return 1;   // str1 más largo, va despues

	return 0;	//escenario donde str1==str2
}

/*
PRE: recibe 2 string de igual largo
POS: copia caracter a caracter del string origen al destino
*/
void copiarString(char* origen, char* destino) {
	int i = 0;
	while (origen[i] != '\0') {
		destino[i] = origen[i];
		i++;
	}
	destino[i] = '\0';
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
	//con insertion sort
	for (int i = 1; i < largoVec; i++) {
		int j = i;
		while ((vec[j - 1] > vec[j]) && (j > 0)) {
			Intercambiar(vec, largoVec, j, j - 1);
			j--;
		}
	}
}

int* intercalarVector(int* v1, int* v2, int l1, int l2){
	//similar merge

	if (l1 == 0 && l2 == 0) {
		return NULL;
	}
		
	int i = 0;
	int j = 0;
	int k = 0;
	int* vec = new int [l1 + l2];

	while ((i < l1) && (j < l2)) {
		if (v1[i] <= v2[j]) {
			vec[k] = v1[i];
			i++;
		}
		else {
			vec[k] = v2[j];
			j++;
		}
		k++;
	}
	//Casos para terminar iteracion en cualquier caso
	while (i < l1) {
		vec[k] = v1[i];
		i++;
		k++;
	}
	while (j < l2) {
		vec[k] = v2[j];
		j++;
		k++;
	}
	return vec;
}

bool subconjuntoVector(int* v1, int* v2, int l1, int l2) {
	if (l1 == 0) {
		return true;
	}
	int i = 0;
	while (i < l1 && elementoPertenece(v2, l2, v1[i])){ 
		i++;
	}
	return (i == l1);
}

char* invertirCase(char* str) {
	int largo = largoString(str);

	char* invertido = new char[largo + 1];

	int i = 0;
	while (i < largo) {
		if (caracterEsMinuscula(str[i])) {
			invertido[i] = convertirAMayuscula(str[i]);
		}
		else if (caracterEsMayuscula(str[i])){
			invertido[i] = convertirAMinuscula(str[i]);
		}
		else {
			invertido[i] = str[i];
		}
		i++;
	}
	invertido[largo] = '\0';
	return invertido;
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

char **ordenarVecStrings(char **vecStr, int largoVecStr) {

	char** nuevo = new char*[largoVecStr];
	int i = 0;

	//Logica para copiar el vector original en el mismo orden que viene
	while (i < largoVecStr) {
		int largo = largoString(vecStr[i]);
		nuevo[i] = new char[largo + 1];
		copiarString(vecStr[i], nuevo[i]);
		i++;
	}

	//Ordenamiento bubble-sort
	for (int i = 0; i < largoVecStr - 1; i++) {
		for (int j = 0; j < largoVecStr - 1 - i; j++) {
			if (compararString(nuevo[j], nuevo[j + 1]) > 0) {	//condicion para intercambiar
				char* temp = nuevo[j];
				nuevo[j] = nuevo[j + 1];
				nuevo[j + 1] = temp;
			}
		}
	}
	return nuevo;
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

#include "Islas.h"
#include <iostream>
using namespace std;

#define AGUA 0
#define TIERRA 1
#define VISITADO 2

void muestroMapa(int** mapa, int M, int N);
int contarIslas(int** mapa, int M, int N);
void borroIsla(int** mapa, int M, int N, int x, int y);
void restablecerTierras(int** mapa, int M, int N);
int** creoMapa(int M, int N);

void islas()
{
	int M = 10;
	int N = 12;

	int** mapa = creoMapa(M, N);
	muestroMapa(mapa, M, N);

	int cant = contarIslas(mapa, M, N);
	cout << "La cantidad de islas encontradas es: " << cant << "\n";
	muestroMapa(mapa, M, N);

	cout << "Restablezco tierras\n";
	restablecerTierras(mapa, M, N); // paso los visitados de vuelta a tierras
	muestroMapa(mapa, M, N);

	system("pause");
}

int contarIslas(int** mapa, int M, int N)
{
	int cant = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (mapa[x][y] == TIERRA) { // si encuentro una tierra
				cant++; // encontre una isla
				borroIsla(mapa, M, N, x, y); // borro toda la isla para no contarla 2 veces (marco como visitada)
			}
		}
	}
	return cant;
}

void borroIsla(int** mapa, int M, int N, int x, int y)
{
	if (x < 0 || y < 0 || x >= M || y >= N) // Me fui de los bordes
		return;
	if (mapa[x][y] != TIERRA) // O es agua o ya fue visitado
		return;
	mapa[x][y] = VISITADO;
	// visito los contiguos la isla actual
	borroIsla(mapa, M, N, x, y + 1);
	borroIsla(mapa, M, N, x + 1, y + 1);
	borroIsla(mapa, M, N, x + 1, y);
	borroIsla(mapa, M, N, x + 1, y - 1);
	borroIsla(mapa, M, N, x, y - 1);
	borroIsla(mapa, M, N, x - 1, y - 1);
	borroIsla(mapa, M, N, x - 1, y);
	borroIsla(mapa, M, N, x - 1, y + 1);
}

void muestroMapa(int** mapa, int M, int N)
{
	cout << "\n";
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++)
			cout << mapa[x][y] << " ";
		cout << "\n";
	}
	cout << "\n";
}

void restablecerTierras(int** mapa, int M, int N)
{
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			if (mapa[x][y] == VISITADO)
				mapa[x][y] = TIERRA;
}

int** creoMapa(int M, int N)
{
	int** mapa = new int* [M]; // Creo la matriz. En realidad es un vector de vectores de enteros
	for (int x = 0; x < M; x++) {
		mapa[x] = new int[N]; // Creo los vectores de enteros y los asigno al vector de la matriz
		for (int y = 0; y < N; y++) {
			mapa[x][y] = AGUA;
		}
	}

	// NO ES NECESARIO QUE COPIES TODO ESTO, con el dibujo de la tabla alcanza:

	mapa[3][0] = TIERRA;
	mapa[4][0] = TIERRA;
	mapa[8][0] = TIERRA;
	mapa[2][1] = TIERRA;
	mapa[4][1] = TIERRA;
	mapa[8][1] = TIERRA;
	mapa[9][1] = TIERRA;
	mapa[1][2] = TIERRA;
	mapa[4][2] = TIERRA;
	mapa[5][2] = TIERRA;
	mapa[6][2] = TIERRA;
	mapa[1][3] = TIERRA;
	mapa[7][3] = TIERRA;
	mapa[2][4] = TIERRA;
	mapa[4][4] = TIERRA;
	mapa[6][4] = TIERRA;
	mapa[9][4] = TIERRA;
	mapa[2][5] = TIERRA;
	mapa[6][5] = TIERRA;
	mapa[9][5] = TIERRA;
	mapa[2][6] = TIERRA;
	mapa[6][6] = TIERRA;
	mapa[9][6] = TIERRA;
	mapa[3][7] = TIERRA;
	mapa[4][7] = TIERRA;
	mapa[5][7] = TIERRA;
	mapa[8][7] = TIERRA;
	mapa[7][8] = TIERRA;
	mapa[6][9] = TIERRA;
	mapa[2][10] = TIERRA;
	mapa[3][10] = TIERRA;
	mapa[6][10] = TIERRA;
	mapa[8][10] = TIERRA;
	mapa[9][11] = TIERRA;

	return mapa;
}
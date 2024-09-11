#ifndef STRASSEN
#define STRASSEN

#include "classic.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define vvi vector<vector<int> >
using namespace std;

// Función que calcula suma de matrices
void add(vvi &mA, vvi &mB, vvi &mC, int n){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			mC[i][j] = mA[i][j] + mB[i][j];
		}
	}
}

// Función que calcula resta de matrices
void substract(vvi &mA, vvi &mB, vvi &mC, int n){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			mC[i][j] = mA[i][j] - mB[i][j];
		}
	}
}

// Función que multiplica matrices con metodo Strassen
// recibe las matrices a multiplicar por referencia y su lado
// y retorna matriz resultado
void strassen(vvi &mA, vvi &mB, vvi &mR, int len){

	// Caso base para matrix <= 16*16
	// llama a multiplicación clásica en caso base
	if (len <= 16){
		classic(mA, mB, mR, len, len, len);}
	else {
		int n = len/2;

		vector<int> row(n, 0);

		// Inicializando sub matrices necesarias
		// partes de las originales mA y mB
		vvi a(n, row), b(n,row), c(n,row), d(n,row);
		vvi e(n,row), f(n,row), g(n,row), h(n,row);

		//almacenarán operaciones parciales
		vvi p1(n, row), p2(n, row), p3(n, row), p4(n, row);
		vvi p5(n, row), p6(n, row), p7(n, row);

		// para valores temporales
		vvi t1(n, row), t2(n, row), t3(n, row), t4(n, row);

		// poblando submatrices a-h
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				// submatrices A
				a[i][j]=mA[i][j];
				b[i][j]=mA[i][j+n];
				c[i][j]=mA[i+n][j];
				d[i][j]=mA[i+n][j+n];

				// submatrices B
				e[i][j]=mB[i][j];
				f[i][j]=mB[i][j+n];
				g[i][j]=mB[i+n][j];
				h[i][j]=mB[i+n][j+n];

			}
		}

		
		//realiza las operaciones parciales 
		substract(f, h, t1, n);
		strassen(a, t1, p1, n);
		add(a, b, t1, n);
		strassen(t1, h, p2, n);
		add(c, d, t1, n);
		strassen(t1, e, p3, n);
		substract(g, e, t1, n);
		strassen(t1, d, p4, n);
		add(a, d, t1, n);
		add(e, h, t2, n);
		strassen(t1, t2, p5, n);
		substract(b, d, t1, n);
		add(g, h, t2, n);
		strassen(t1, t2, p6, n);
		substract(a, c, t1, n);
		add(e, f, t2, n);
		strassen(t1, t2, p7, n);

		// almacena operaciones finales en var temporales
		// más eficiente que llamar a las funciones para suma y resta individualmente
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				t1[i][j] = p5[i][j]+p4[i][j]-p2[i][j]+p6[i][j];
				t2[i][j] = p1[i][j]+p2[i][j];
				t3[i][j] = p3[i][j]+p4[i][j];
				t4[i][j] = p1[i][j]+p5[i][j]-p3[i][j]-p7[i][j];
			}
		}

		// poblando matriz resultado
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				mR[i][j] = t1[i][j];
				mR[i][j+n] = t2[i][j];
				mR[i+n][j] = t3[i][j];
				mR[i+n][j+n] = t4[i][j];
			}
		}
	}
}



#endif //strassen
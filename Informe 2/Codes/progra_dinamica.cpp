#include "utilidades.h"

// PROGRAMACIÓN DINÁMICA
/*
Función que calcula distancia mínima de edición por programación dinámica
recibe matriz de distancias parciales (vacía)
retorna el costo mínimo de edición
*/
int edit_dist_dp(){

	// matriz de costos parciales
	vvi dist(lena+1, (vector<int>(lenb+1)));
	
	// CASOS BASE
    
    dist[0][0]=0;

    int c=0;
    for (int i=1; i<= lena; i++){
        c+=c_del(a[i-1]);
        dist[i][0] = c;
    }
    c=0;
    for (int j=1; j<=lenb;j++){
        c+=c_ins(b[j-1]);
        dist[0][j] = c;
    }

    // ITERACIÓN
    for (int i=1; i<=lena; i++){
        for (int j=1; j<=lenb; j++){
            dist[i][j] = min(
                dist[i-1][j]+ c_del(a[i-1]), min(           // eliminación
                dist[i][j-1] + c_ins(b[j-1]),               // inserción
                dist[i-1][j-1] + c_sub(a[i-1], b[j-1])));   // sustitución
            if (i>1 && j>1 && a[i-1] == b[j-2] && a[i-2] == b[j-1]){
                dist[i][j] = min(dist[i][j], dist[i-2][j-2] + c_trans(a[i-1], a[i-2])); // transposición
            }
        }
    }

    return dist[lena][lenb];
}
#include "utilidades.h"


// FUERZA BRUTA
/*
Función que calcula distancia mínima de edición por fuerza bruta
recibe: 
	int i: índice actual en a
	int j: índice actual en b
	int cost: costo acumulado hasta el momento
retorna el costo mínimo de edición

OBS: cuando version = false implementa la solución exhaustiva normal,
cuando version = true implementa la mejora propuesta en el informe.
*/
int edit_dist_fb(int i, int j, int cost){

    // CASOS BASE

    //if (i==lena && j==lenb) return cost;    // terminaron ambos string
    if (i==lena) {                          // insertar lo que queda en b
        for (int x=j; x<lenb; x++){
            cost += c_ins(b[x]);
        }
        return cost;
    } 
    if (j==lenb) {                          // eliminar lo que sobra en a
        for(int x=i; x<lena; x++){
            cost += c_del(a[x]);
        }
        return cost;
    }

    // mejora propuesta
    if(version && (a[i]==b[j])){
    	return edit_dist_fb(i+1, j+1, cost);
    } 

    // RECURSIÓN - caso con transposición
    if (i+1<lena && j+1<lenb){
        if ((a[i]==b[j+1])&&(a[i+1]==b[j])){    // si podemos trasponer
            return min(min(
		        edit_dist_fb(i, j+1, cost + c_ins(b[j])),				// inserción
		        edit_dist_fb(i+1, j, cost + c_del(a[i]))), min( 		// eliminación
		        edit_dist_fb(i+1, j+1, cost + c_sub(a[i], b[j])),		// sustitución
		        edit_dist_fb(i+2, j+2, cost + c_trans(a[i], a[i+1]))	// transposición
		        ));              
		}
    }


    // RECURSIÓN - caso sin transposición
    return min(
        edit_dist_fb(i, j+1, cost + c_ins(b[j])), min(         // inserción     
        edit_dist_fb(i+1, j, cost + c_del(a[i])),              // eliminación
        edit_dist_fb(i+1, j+1, cost + c_sub(a[i], b[j]))));    // sustitución
}
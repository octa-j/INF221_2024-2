#include <iostream>
#include <sstream>
#include <math.h>
#include <string>

using namespace std;

string a, b;
int lena, lenb;

/*
Algoritmo diseñado con el paradigma de fuerza bruta
Calcula la distancia mínima de edición entre dos palabras
- evalúa todas las opciones exhaustivamente
- busca el mínimo entre las opciones
- buscamos transformar el string a en el b

Implementación usando el algoritmo de LEVENSHTEIN
 - CON TRANSPOSICIÓN
 - CON COSTOS VARIABLES

Operaciones posibles
    - insert
    - delete
    - substitute
    - transpose*

* solo realiza tranposición si al cabo de la transposición AMBOS caracteres 
están en su posición final
*/

// Funciones que calculan el costo de una operación determinada

// costos de inserción
int c_ins(char b){
	return 4;
}

// costos de eliminación
int c_del(char a){
	return 3;
}

// costos de sustitución
int c_sub(char a, char b){
	if (a==b) return 0;
    return 2;
}

// costos de transposición
int c_trans(char a1, char a2){
	return 1;
}



// Función que calcula distancia de edición

int edit_distance(int i, int j, int cost){

    // CASOS BASE

    if (i==lena && j==lenb) return cost;    // terminaron ambos string
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

    // RECURSIÓN
    	// con transposición
    if (i+1<lena && j+1<lenb){
        if ((a[i]==b[j+1])&&(a[i+1]==b[j])){    // si podemos trasponer
            return min(min(
		        edit_distance(i, j+1, cost + c_ins(b[j])),				// inserción
		        edit_distance(i+1, j, cost + c_del(a[i]))), min( 		// eliminación
		        edit_distance(i+1, j+1, cost + c_sub(a[i], b[j])),		// sustitución
		        edit_distance(i+2, j+2, cost + c_trans(a[i], a[i+1]))	// transposición
		        ));              
		}
    }



    // RECURSIÓN
    	// sin transposición
    return min(
        edit_distance(i, j+1, cost + c_ins(b[j])), min(         // inserción     
        edit_distance(i+1, j, cost + c_del(a[i])),              // eliminación
        edit_distance(i+1, j+1, cost + c_sub(a[i], b[j]))));    // sustitución
}

// Función main

int main(){
    cout<<"Inserte los strings: ";
    cin>>a>>b;
    
    lena=a.length();
    lenb=b.length();

    int ed_dist = edit_distance(0, 0, 0);

    cout<<"Distancia de edición: "<<ed_dist<<endl;

    return 0;
}

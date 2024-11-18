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
 - SIN TRANSPOSICIÓN
 - SIN COSTOS VARIABLES

Operaciones posibles
    - insert
    - delete
    - substitute
*/

// Funciones que calculan los costos de una operación determinada

// costos de inserción
int c_ins(char b){
    return 2;
}

// costos de eliminación
int c_del(char a){
    return 4;
}

// costos de sustitución
int c_sub(char a, char b){
    if (A==B){
        return 0;
    }
    return 3;
}



// Función que calcula distancia de edición
// recibe los índices sobre los cuales estamos trabajando
// al igual que el costo acumulado hasta el momento

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

    cout<<"distancia de edición: "<<ed_dist<<endl;

    return 0;
}
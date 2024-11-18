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

// Función que calcula distancia de edición
// recibe los índices sobre los cuales estamos trabajando

int edit_distance(int i, int j){

    // CASOS BASE

    if (i==lena && j==lenb) return 0;
    if (i==lena) return lenb-j; // insertar lo que queda en b
    if (j==lenb) return lena-i; // eliminar lo que sobra en a

    if (a[i]==b[j]) return edit_distance(i+1, j+1);

    // RECURSION
    return 1 + min(
        edit_distance(i, j+1), min(         // inserción
        edit_distance(i+1, j),              // eliminación
        edit_distance(i+1, j+1)));          // sustitución
}

// Función main

int main(){
    cout<<"Inserte los strings: ";
    cin>>a>>b;
    
    lena=a.length();
    lenb=b.length();

    int ed_dist = edit_distance(0, 0);

    cout<<"distancia de edición: "<<ed_dist<<endl;

    return 0;
}
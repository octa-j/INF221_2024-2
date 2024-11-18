#include <iostream>
#include <sstream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

string a, b;
int lena, lenb;

/*
Algoritmo diseñado con el paradigma de programación dinámica
Calcula la distancia mínima de edición entre dos palabras
- visita diferentes camino
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
	return 1;

}

// costos de eliminación
int c_del(char a){
	return 1;
}

// costos de sustitución
int c_sub(char a, char b){
	if (a==b) return 0;
    return 1;
}

// costos de transposición
int c_trans(char a1, char a2){
	return 1;
}

void printmatrix(vector<vector<int> > &dist){
    for (int i=0; i<=lena; i++){
        for (int j=0; j<=lenb; j++){
            cout<<dist[i][j]<<"\t";
        }
        cout<<endl;
    }
}

// Función main
/*
Calcula costos de edición, imprime matriz generada
*/
int main(){
    cout<<"Inserte los strings: ";
    cin>>a>>b;
    
    lena=a.length();
    lenb=b.length();

    vector<vector<int> > dist(lena+1, (vector<int>(lenb+1)));

    // inicialización casos base
    dist[0][0]=0;

    int c=0;
    for (int i=1; i<=lena; i++){
        c+=c_del(a[i-1]);
        dist[i][0] = c;
    }
    c=0;
    for (int j=1; j<=lenb;j++){
        c+=c_ins(b[j-1]);
        dist[0][j] = c;
    }

    // cálculo de distancias de edición iterativamente
    for (int i=1; i<=lena; i++){
        for (int j=1; j<=lenb; j++){
            dist[i][j] = min(
                dist[i][j-1] + c_ins(b[j-1]), min(           // inserción
                dist[i-1][j]+ c_del(a[i-1]),               // eliminación
                dist[i-1][j-1] + c_sub(a[i-1], b[j-1])));   // sustitución
            if (i>1 && j>1 && a[i-1] == b[j-2] && a[i-2] == b[j-1]){
                dist[i][j] = min(dist[i][j], dist[i-2][j-2] + c_trans(a[i-1], a[i-2])); // transposición
            }
        }
    }

    printmatrix(dist);

    cout<<"distancia mínima de edición: "<<dist[lena][lenb]<<endl;

    return 0;
}

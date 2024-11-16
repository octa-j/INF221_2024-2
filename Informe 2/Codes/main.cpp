
#include <chrono>
#include <iostream>
#include <math.h>
#include "utilidades.h"

/*
Oct 2024 - INF221
Octavia Jara

Programa para análisis de algoritmos de distancias de edición
Contiene dos enfoques diferentes:
	- fuerza bruta, exhaustivo
	- programación dinámica

La lógica implementada fue basada en los trabajos de Damerau-Levenshtein pero con 
costos de operación variables.

Operaciones posibles:
    - insert
    - delete
    - substitute
    - transpose*

* solo realiza tranposición si al cabo de la transposición AMBOS caracteres 
están en su posición final


Se tienen las siguientes partes:
	- variables globales (& externas)
	- funciones de costo: calculan los costos de las operaciones 		- costos.cpp
	- fuerza bruta: alcance por función recursiva exhaustiva 			- fuerza_bruta.cpp
	- programación dinámica: alcance por función iterativa				- proga_dinamica.cpp
	- main: incializa las variables y funciones de costo
			realiza el cálculo de distancia de edición usando ambos enfoques para las muestras
			almacena el tiempo que toma c/u y lo registra
*/

string name_a, name_b;

string a, b; 		// palabras a trabajar
int lena, lenb; 	// largos de a y b respectivamente

bool version; 		// para versiones de fuerza bruta

// vectores y matrices de costo para las funciones de costo
vi ins(26); 
vi del(26);
vvi sub(26, vector<int>(26));
vvi trans(26, vector<int>(26));

void times_fb(){

	ofstream fb_times ("fb_tiempos_s.csv");

	fb_times<<"lena,lenb,fb0,fb1"<<endl;

	time_point<high_resolution_clock> start_fb_0, end_fb_0;
	time_point<high_resolution_clock> start_fb_1, end_fb_1;

	for (int i=1; i<=30; i++){ //fix
		for (int j=i; j<=30; j++){
			if (i+j>30) continue;

			lena = i;
			lenb = j;
			
			// caso de evaluar los algoritmos de fuerza bruta
			version = false; // fuerza bruta normal
			start_fb_0 = high_resolution_clock::now();
			edit_dist_fb(0, 0, 0);
			end_fb_0 = high_resolution_clock::now();

			version = true; // fuerza bruta con mejora
			start_fb_1 = high_resolution_clock::now();
			edit_dist_fb(0, 0, 0);
			end_fb_1 = high_resolution_clock::now();

			// calcula e imprime los tiempo correspondientes
			duration<long long, micro> dur_fb_0 = duration_cast<microseconds>(end_fb_0-start_fb_0);
			duration<long long, micro> dur_fb_1 = duration_cast<microseconds>(end_fb_1-start_fb_1);

			fb_times<<i<<','<<j<<','<<dur_fb_0.count()<<','<<dur_fb_1.count()<<endl;
	
	
		}
	}

	fb_times.close();


}


void times_dp(){

	ofstream dp_times ("dp_tiempos_s.csv");
	dp_times<<"lena,lenb,dp"<<endl;

	time_point<high_resolution_clock> start_dp, end_dp;

	for (int n = 1; n<5; n++){
		for (int x=1; x<10; x++){
			lena = pow(10,n)*x;
			lenb = lena;

			start_dp = high_resolution_clock::now();
			edit_dist_dp();
			end_dp = high_resolution_clock::now();

			duration<long long, micro> dur_dp = duration_cast<microseconds>(end_dp-start_dp);

			dp_times<<lena<<','<<lenb<<','<<dur_dp.count()<<endl;
		}
	}
	dp_times.close();
}


// FUNCIÓN MAIN
/*
Realiza el ingreso de los archivos
Hace el cálculo de los algoritmos de fuerza bruta para instancias de tamaño razonable.
Hace el cálculo del algoritmo de programación dinámica.
Imprime los resultado en el archivo tiempos.csv para posterior análisis.

*/
int main(){

	cout<<"Bienvenido! :)"<<endl;
	cout<<"Ingrese nombres de los archivos para strings a y b"<<endl;
	cout<<"ej. a.txt b.txt : ";
	cin>>name_a>>name_b;

	setup();

	times_dp();
	times_fb();

	return 0;
}

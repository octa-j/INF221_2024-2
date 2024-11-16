#include <vector>
#include <string>
#include <fstream>

using namespace std;
using namespace std::chrono;

#define vi vector<int>
#define vvi vector<vi >

#ifndef UTILIDADES_H
#define UTILIDADES_H

// VARIABLES GLOBALES
extern string name_a, name_b;

extern string a, b; 		// palabras a trabajar
extern int lena, lenb; 	// largos de a y b respectivamente

extern bool version; 		// para versiones de fuerza bruta

// vectores y matrices de costo para las funciones de costo
extern vi ins; 
extern vi del;
extern vvi sub;
extern vvi trans;

// costos
int c_ins(char a);
int c_del(char a);
int c_sub(char a, char b);
int c_trans(char a1, char a2);

void setup();

// fuerza bruta
int edit_dist_fb(int i, int j, int cost);

// programación dinámica
int edit_dist_dp();

#endif
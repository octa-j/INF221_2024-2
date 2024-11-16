
#include "utilidades.h"
#include <iostream>

// FUNCIONES DE COSTO
	// costos de inserción
int c_ins(char b){
	return ins[b-97];
}

	// costos de eliminación
int c_del(char a){
	return del[a-97];
}

	// costos de sustitución
int c_sub(char a, char b){
	if (a==b) return 0;
    return sub[a-97][b-97];
}

	// costos de transposición
int c_trans(char a1, char a2){
	return trans[a1-97][a2-97];
}

// función que ingresa los costos desde los archivos correspondientes
// también lee 
void setup(){

	ifstream file_ins ("../datasets/c_ins.txt");
	ifstream file_del ("../datasets/c_del.txt");
	ifstream file_sub ("../datasets/c_sub.txt");
	ifstream file_trans ("../datasets/c_trans.txt");

	bool first = true;

	for (int i=0; i<26; i++){
		for (int j=0; j<26; j++){
			if (first){ 			// relleno vectores ins, del
				file_ins>>ins[j];
				file_del>>del[j];
			}
			file_sub>>sub[i][j];	// relleno matrices sub, trans
			file_trans>>trans[i][j];
		}
		first = false;
	}

	ifstream file_a("../datasets/"+name_a);
	ifstream file_b("../datasets/"+name_b);

	file_a>>a;
	file_b>>b;
}
#ifndef TRANSPOSED
#define TRANSPOSED

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define vvi vector<vector<int> >
using namespace std;

void transpose(vvi &m, vvi &T, int length, int width){
    for (int i=0; i<length; i++){
        for (int j=0; j<width; j++){
            T[j][i] = m[i][j];
        }
    }
}

void transposed(vvi& mA, vvi& mB, vvi& mR, int lengthA, int wlAB, int widthB){
    for (int i=0; i<lengthA; i++){
        for (int j=0; j<widthB; j++){
            mR[i][j]=0;
            for (int k=0; k<wlAB; k++){
                mR[i][j]+= mA[i][k]*mB[j][k];
            }
        }
    }    
}

#endif //transposed
#ifndef CLASSIC
#define CLASSIC

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define vvi vector<vector<int> >
using namespace std;

void classic(vvi& mA, vvi& mB, vvi& mR, int lengthA, int wlAB, int widthB){
    for (int i=0; i<lengthA; i++){
        for (int j=0; j<widthB; j++){
            mR[i][j]=0;
            for (int k=0; k<wlAB; k++){
                mR[i][j]+= mA[i][k]*mB[k][j];
            }
        }
    }    
}

#endif //classic
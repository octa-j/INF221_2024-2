#include "classic.h"
#include "transposed.h"
#include "strassen.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define vvi vector<vector<int> >
using namespace std;

int main(){
    int algNum, maxlengthA, maxwlAB, maxwidthB;

    cout<<"Insert the corresponding algorithm number"<<endl;
    cout<<"1. Traditional Cubic\n2. Optimized Cubic\n3. Strassen"<<endl;
    cin>>algNum;

    cout<<"Insert matrix A max length: ";
    cin>>maxlengthA;
    cout<<"Insert matrix A max width and matrix B max length: ";
    cin>>maxwlAB;
    cout<<"Insert matrix B max width: ";
    cin>>maxwidthB;
    cout<<endl;

    ifstream numsA ("randomA.txt");
    ifstream numsB ("randomB.txt");
    vector<int> madreA(maxlengthA*maxwlAB);
    vector<int> madreB(maxwlAB*maxwidthB);
    for(int i=0; i<maxlengthA*maxwlAB; i++){
        numsA>>madreA[i];
    }
    for(int i=0; i<maxwlAB*maxwidthB; i++){ 
        numsB>>madreB[i];
    }


    int lengthA=0, wlAB=0, widthB=0;

    for (float p=1; p<=1; p+=1){ /// change to p = 0.1 & += 0.1
        lengthA = maxlengthA*p;
        wlAB = maxwlAB*p;
        widthB = maxwidthB*p;

        vvi mA(lengthA, vector<int>(wlAB));
        vvi mB(wlAB, vector<int>(widthB));
        vvi mT(widthB, vector<int>(wlAB));
        vvi mR(lengthA, vector<int>(widthB));

        for (int i=0; i<lengthA; i++){
            for (int j=0; j<wlAB; j++){
                mA[i][j]=madreA[wlAB*i+j];
            }
        }

        for (int i=0; i<wlAB; i++){
            for (int j=0; j<widthB; j++){
                mB[i][j]=madreB[(widthB*i)+j];
            }
        }

        switch (algNum){
            case 1:{
                classic(mA, mB, mR, lengthA, wlAB, widthB);
                break;
            }
            case 2:{
                transpose(mB, mT, wlAB, widthB);
                transposed(mA, mT, mR, lengthA, wlAB, widthB);
                break;
            }
            case 3:{
                mR = strassen(mA, mB, lengthA);
                break;
            }
        }

        for (int i=0; i<lengthA; i++){
            for (int j=0; j<widthB; j++){
                cout<<mR[i][j]<<" ";
            }
            cout<<endl;
        }

    }
    


    return 0;
}
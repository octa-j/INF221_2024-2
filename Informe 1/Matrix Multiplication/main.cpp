#include "classic.h"
#include "transposed.h"
#include "strassen.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <math.h>

#define vvi vector<vector<int> >
using namespace std;
using namespace chrono;

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

    string fileName;
    cout<<"Insert output file name: ";
    cin>>fileName;
    cout<<endl;
    ofstream out;
    out.open(fileName);

    int lengthA=1, wlAB=1, widthB=1;

    while (lengthA<maxlengthA && wlAB<maxwlAB && widthB<maxwidthB){
        lengthA *=2;
        wlAB *=2;
        widthB *=2;

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

        

        time_point<std::chrono::system_clock> start, end;
        start = system_clock::now();

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
                strassen(mA, mB, mR, lengthA);
                break;
            }
        }
        end = system_clock::now();
        int duration = duration_cast<microseconds>(end - start).count();
        int size = sqrt(((lengthA+ widthB)*wlAB)/2);
        out << size<<","<<duration<<endl;

    }

    return 0;
        

}
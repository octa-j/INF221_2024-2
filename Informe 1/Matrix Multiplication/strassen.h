#ifndef STRASSEN
#define STRASSEN

#include "classic.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define vvi vector<vector<int> >
using namespace std;

void add(vvi mA, vvi mB, vvi& matrix_C, int len2){
	for (int i = 0; i < len2; i++)
		for (int j = 0; j < len2; j++)
			matrix_C[i][j]
				= mA[i][j] + mB[i][j];
}

vvi strassen(vvi &mA, vvi &mB, int len){
    vvi mR(len, vector<int>(len, 0));

	if (len <= 7){
		classic(mA, mB, mR, len, len, len);}
	else {
		int len2 = len/2;

		vector<int> row_vector(len2, 0);
		vvi mR_00(len2, row_vector);
		vvi mR_01(len2, row_vector);
		vvi mR_10(len2, row_vector);
		vvi mR_11(len2, row_vector);

		vvi mA_00(len2, row_vector);
		vvi mA_01(len2, row_vector);
		vvi mA_10(len2, row_vector);
		vvi mA_11(len2, row_vector);
		vvi mB_00(len2, row_vector);
		vvi mB_01(len2, row_vector);
		vvi mB_10(len2, row_vector);
		vvi mB_11(len2, row_vector);

		for (int i = 0; i < len2; i++)
			for (int j = 0; j < len2; j++) {
				mA_00[i][j] = mA[i][j];
				mA_01[i][j] = mA[i][j + len2];
				mA_10[i][j] = mA[len2 + i][j];
				mA_11[i][j] = mA[i + len2][j + len2];
				mB_00[i][j] = mB[i][j];
				mB_01[i][j] = mB[i][j + len2];
				mB_10[i][j] = mB[len2 + i][j];
				mB_11[i][j] = mB[i + len2][j + len2];
			}
        cout<<"hola"<<endl;
		add(strassen(mA_00, mB_00, len2), strassen(mA_01, mB_10, len2), mR_00, len2);
		add(strassen(mA_00, mB_01, len2), strassen(mA_01, mB_11, len2), mR_01, len2);
		add(strassen(mA_10, mB_00, len2), strassen(mA_11, mB_10, len2), mR_10, len2);
		add(strassen(mA_10, mB_01, len2), strassen(mA_11, mB_11, len2), mR_11, len2);

		for (int i = 0; i < len2; i++)
			for (int j = 0; j < len2; j++) {
				mR[i][j] = mR_00[i][j];
				mR[i][j + len2]= mR_01[i][j];
				mR[len2 + i][j]= mR_10[i][j];
				mR[i + len2][j + len2]= mR_11[i][j];
			}

	}
	return mR;
}



#endif //strassen
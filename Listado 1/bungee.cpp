#include <iostream>

using namespace std;


int main(){

    int N;
    cin>>N;
    int H[N];

    for (int i=0; i<N; i++){
        cin>>H[i];              
    }

    int max=0;
    int mmax = 0;
    int top = 0;
    for (int i=1; i<N; i++){ // goes right

        if (H[i]<H[top]){
            if (H[top]-H[i]>mmax){
                mmax = H[top] - H[i];
            }
        }
        else{
            top = i;
            if (i !=top+1 && max < mmax){
                max = mmax;
            }
            else mmax = 0;
        }
    }

    mmax = 0;
    top = N-1;
    for (int i=N-2; i>=0; i--){ // goes left

        if (H[i]<H[top]){
            if (H[top]-H[i]>mmax){
                mmax = H[top] - H[i];
            }
        }
        else{
            top = i;
            if (i !=top+1 && max < mmax){
                max = mmax;
            }
            else mmax = 0;
        }
    }

    cout<<max<<endl;





}
#include <iostream>

using namespace std;


int main(){

    int N, Y;
    cin>>N>>Y;
    int nums[N];
    int k;

    for (int j = 0; j<N; j++){
        nums[j]=0;
    }

    for (int i = 0; i<Y; i++){
        cin>>k;
        nums[k]=1;
    }

    int X=0;
    for (int j = 0; j<N; j++){
        if (nums[j]==1){
            X++;
        }
        else{
            cout<<j<<endl;
        }
    }

    cout<<"Mario got "<<X<<" of the dangerous obstacles."<<endl;




    return 0;
}
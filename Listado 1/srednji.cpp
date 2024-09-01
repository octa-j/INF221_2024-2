#include <iostream>
#include <vector>

using namespace std;

int main(){
    int size, med;
    cin>>size>>med;
    
    vector<int> nums(size, 0);
    int posM;

    for (int i=0; i<size; i++ ){
        int n;
        cin>>n;
        nums[i] = n;
        if (n == med) posM = i; ///
    }

    int found = 0;

    for (int j=0; j<=posM; j++){
        bool val = false;
        int total = 0;

        for (int k=j; k<size; k++){
            if (nums[k]>med) total++;
            else if (nums[k]<med) total--;
            else val = true;

            if (val && !total) found++;
        }    
    }

    cout<<found<<endl;

    return 0;
}
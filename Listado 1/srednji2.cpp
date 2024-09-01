#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){
    int len, med;
    cin>>len>>med;
    
    int posM;

    vector<int> nums (len, 0);

    for (int i =0; i<len; i++){
        int n;
        cin>>n;
        nums[i]=n;
        if (n==med) posM = i;
    }

    map<int, int> balance;
    int sum = 0;
    int total = 0;

    balance[0] = 1;

    for (int i=posM+1; i<len;i++){
        if (nums[i]>med) sum++;
        else sum --;
        balance[sum]++;
    }
    
    total += balance[0];
    sum=0;

    for (int i=posM-1; i>=0; i--){
        if (nums[i]>med) sum++;
        else sum--;
        total += balance[-sum];
    }

    cout<<total<<endl;
    return 0;
}
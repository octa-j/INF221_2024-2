#include <iostream>
#include <stack>

using namespace std;

int main(){
    int N, K;
    cin>>N>>K;
    int ins[K];

    string inp;
    stack<int> nums;
    int del=0;

    for (int i=0; i<K; i++){
        cin>>inp;
        if (inp[0]!= 'u'){
            nums.push(stoi(inp));
        }
        else{
            cin>>del;
            for (int j=0; j<del; j++){
                nums.pop();
            }    
        }
    }

    int person =0;

    while (!nums.empty()){
        person = ((person + nums.top())%N + N) %N;
        nums.pop();
    }
    cout<<person<<endl;

    return 0;
}
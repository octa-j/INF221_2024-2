#include <iostream>
#include <sstream>
#include <deque>
#include <string>

using namespace std;

int main(){
    int cases;
    cin>>cases;

    for (int i=0; i<cases; i++){
        string code;
        int len;
        cin >>code>>len;

        bool err=false;

        deque<int> nums;
        string l;
        cin>>l;

        l = l.substr(1, l.length()-2);
        stringstream ss(l);
        string num;

        while(getline(ss,  num, ',')){
            nums.push_back(stoi(num)); 
        }


        bool R=false;

        for (char c : code){
            switch (c){
                case 'R':{
                    R = !R;
                    break;
                }
                case 'D':{
                    if (nums.empty()) {
                        err = true;
                        break;
                    }
                    else if (R){
                        nums.pop_back();
                    }
                    else {
                        nums.pop_front();
                    }
                    break;
                }
            }
            if (err) break;
        }
        
        if (err){
            cout<<"error"<<endl;
        }
        else if (nums.empty()) cout<<"[]"<<endl;
        else{
            cout<<"[";
            if (!R){
                for (int j=0; j<nums.size()-1; j++){
                    cout<<nums[j]<<",";
                }
                cout<<nums[nums.size()-1]<<"]"<<endl;
            }
            else {
                for (int j=nums.size()-1;j>0;j--){
                    cout<<nums[j]<<",";
                }
                cout<<nums[0]<<"]"<<endl;
            }
        }
    }
    return 0;
}
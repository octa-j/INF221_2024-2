#include <iostream>
#include <vector> 
#include <algorithm>
#include <math.h>
#include <sstream>

using namespace std;

bool comp(pair<long int, string> a,pair<long int, string> b){
    if (a.first > b.first) return true;
    if (b.first > a.first) return false;
    return (a.second <= b.second);

};


int main(){
    int cases;
    cin>>cases;
    
    for (int i=0; i<cases; i++){
        int persons;
        cin>>persons;

        vector<pair<long int,string> > classes;

        for (int j=0; j<persons; j++){
            string name, rank, nn;
            cin>>name>>rank>>nn;

            stringstream ss(rank);
            string classs;
            
            long int value=0;
            int k=0;

            while(getline(ss,  classs, '-')){
                switch(classs[0]){
                    case 'u':{
                        value += 2*pow(10, k);
                        break;
                    }

                    case 'm':{
                        value += pow(10,k);
                        break;
                    }

                    case 'l': break;
                }
                k++;
            }

            while(k<10){
                value = value*10;
                value++;
                k++;
            }
    

            pair<long int, string> person;
            person.first = value;
            person.second = name.substr(0, name.length()-1);
            classes.push_back(person);  //<-------------HAVB
        }

        sort(classes.begin(), classes.end(), comp);
      
        for (pair<long int, string> person: classes){
            cout<<person.second<<endl;
        }
        cout<<"=============================="<<endl;
    }
    return 0;
}
#include <iostream>
#include <list>
#include <string>

using namespace std;

int main(){
    int cases;
    cin>>cases;
    cin.ignore();

    while(cases--){
        string line;
        getline(cin, line);
        list<char> final;
        list<char>::iterator pos = final.begin();

        for (int i=0; i<line.length(); i++){
            char c = line[i];
            switch(c){
                case ']': {
                    pos = final.end();
                    break;}
                
                case '[': {
                    pos = final.begin();
                    break;}

                case '<': {
                    if (pos != final.begin()){
                        pos = final.erase(--pos);
                    }
                    break;}

                default: {
                    pos = final.insert(pos, c);
                    pos++;
                    break;}
                }
            }

        
        for (char c : final){
            cout<<c;
        }
        cout<<endl;
    }
    return 0;
}


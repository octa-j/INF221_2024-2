#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>

using namespace std;

int reception(vector<string> &words) {
    string line;
    int size=0;
    while (getline(cin, line)){
        if (line=="")break;
        stringstream s(line);
        string word;
        while (s>>word){
            words.push_back(word);
            size++;
        }
    }
    return size;
}


int main(){
    vector<string> words;
    int size = reception(words);
    
    set<string> comb;

    for (int i=0; i<size; i++){
        string pal1=words[i];
        for (int j=i+1; j<size; j++){
            string pal2=words[j];
            comb.insert(pal1+pal2);
            comb.insert(pal2+pal1);
        }
    }
    for (string pal:comb){
        cout<<pal<<endl;
    }
}
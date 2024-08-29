#include <iostream>
#include <string>
#include <map>
using namespace std;

// function that receives bids and asks, processes the sales required
void sale( map<int, int, greater<int> >& b, map<int, int, less<int> >& a){

    // these conditionals are the check which has excedent, if any
    // removes the element left with amount 0
    if (a.begin()->second > b.begin()->second){ 
        a.begin()->second -= b.begin()->second;
        b.erase(b.begin()); 
    } 
    else if (a.begin()->second == b.begin()->second){
        b.erase(b.begin());
        a.erase(a.begin());
    }
    else {
        b.begin()->second -= a.begin()->second;
        a.erase(a.begin());
    }
}


// function receives bids asks, and last sale price
// prints to screen the lowest ask, highest bid and last sale price
// prints - if not aplicable
void showData (map<int, int, greater<int> >& bids, map<int, int, less<int> >& asks, int last){
    if (!asks.empty()) {
        cout<<asks.begin()->first<<" ";}
    else {
        cout<<"- ";}
    if (!bids.empty()) {
        cout<<bids.begin()->first<<" ";}
    else {
        cout<<"- ";}
    if (last !=0) {
        cout<<last<<" ";}
    else {
        cout<<"- ";}
    cout<<endl;
}




int main(){
    int tests;
    cin >>tests;

    for (int i=0; i<tests; i++){
        int last = 0;
        int orders;
        cin>>orders; //amt of orders

        // defining variables
        string type, nn;
        int amt, price, stockPrice;
        stockPrice = 1001;
        
        // defines dictionaries that will save data, keys are prices and store amount
        map<int, int, greater<int> > bids;
        map<int, int, less<int> > asks;

        for (int j=0; j<orders; j++){ // works every order
            cin>>type>>amt>>nn>>nn>>price; //calls in all the stuff
            switch (type[0]){ //analyses firsth character of first word
                case 'b':{
                    bids[price] += amt;
                    break;
                }
                case 's':{
                    asks[price] += amt;
                    break;
                }
            }

            while (!bids.empty() && !asks.empty() && (bids.begin()->first >= asks.begin()->first)){ //checks if sales are possible
                last = asks.begin()->first; // last sale price
                sale(bids, asks); // proceses sale
                }

            showData(bids, asks, last); // outputs as required
            }
        }
    return 0;
    }
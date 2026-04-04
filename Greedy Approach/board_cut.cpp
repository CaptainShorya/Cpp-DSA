// Minimum Cost to Cut a Board into Squares
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b){
    return a > b; //Decreasing Order 
}

int minCostToCutBoard(vector<int> X, vector<int> Y, int M, int N){ // TC = O(nlogn) due to sorting
    //Number of horizontal and vertical blocks
    int hz = 1;
    int vr = 1;
    int h = 0, v = 0;
    sort(X.begin(),X.end(),cmp);
    sort(Y.begin(),Y.end(),cmp);
    int totalCost = 0;
    while(v < X.size() && h < Y.size()){ // O(m Or n) ->size 
        if(X[v] > Y[h]){ // vertical cut cost greater than horizontal cut cost => apply vertical cut
            totalCost += X[v]*vr; // cost multiplied by current vertical segments
            hz++;
            v++;
        }else{
            totalCost += Y[h]*hz; // cost multiplied by current horizontal segments
            vr++;
            h++;
        }
    }
    // If vertical cuts remain, apply them
    while(v != X.size()){ 
        totalCost += X[v]*vr;
        v++;
    }
    // If horizontal cuts remain, apply them
    while(h != Y.size()){ 
        totalCost += Y[h]*hz;
        h++;
    }
    return totalCost;
}

int main(){
    int M = 6;
    int N = 4;
    vector<int> X = {2,1,3,1,4}; // Vertical Cut cost
    vector<int> Y = {4,1,2}; // Horizontal Cut cost
    cout << minCostToCutBoard(X,Y,M,N) << endl;
    return 0;
}
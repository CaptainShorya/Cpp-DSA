#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minProduct(vector<int>& vec){
    int minPosElem = INT_MAX;
    int maxNegElem = INT_MIN;
    int negCount = 0;
    int zeroes = 0;
    long long prodNegatives = 1;
    long long prodPositives = 1;
    for(int i=0; i<vec.size(); i++){
        if(vec[i] > 0){
            minPosElem = min(minPosElem,vec[i]);
            prodPositives *= vec[i];
        }
        else if(vec[i] == 0) zeroes++;
        else{
            negCount++;
            maxNegElem = max(maxNegElem,vec[i]);
            prodNegatives *= vec[i];
        }
    }
    if(zeroes == vec.size()) return 0;
    if(negCount == 0){
        if(zeroes > 0) return 0;
        return minPosElem;
    }
    //even
    if(negCount%2 == 0) return prodNegatives/maxNegElem;
    //odd
    return prodNegatives*prodPositives;
}

int main(){
    vector<int> vec = {-2,-3,1,4,-2,-5};
    cout << minProduct(vec) << endl;
    return 0;
}
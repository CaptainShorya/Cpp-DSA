#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

//In leetcode, Time Limit Exceeded for this code as it is of Time Complexity of O(n^2)
int maxSightseeing(vector<int> values){
    int score = INT_MIN;
    for(int i=0; i<values.size(); i++){
        for(int j=i+1; j<values.size(); j++){
            score = max(values[i] + values[j] + i - j,score);
        }
    }
    return score;
}

int sightseeing(vector<int> arr){
    int score = INT_MIN;
    int i=0;
    int j = arr.size() - (i+1);
    for(int i=0; i<arr.size(); i++){
        score = max(arr[i] + arr[j] + i - j, score);
    }
}

int main(){
    vector<int> values = {1,2};
    cout << sightseeing(values);
    return 0;
}
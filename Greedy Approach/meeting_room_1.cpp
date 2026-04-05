#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Code Here
        auto cmp = [](vector<int>a, vector<int>b){
            return a[0] < b[0];
        };
        sort(arr.begin(),arr.end(),cmp);
        for(int i=1; i<arr.size(); i++){
            if(arr[i][0] < arr[i-1][1]){
                return false;
            }
        }
        return true;
    }
};
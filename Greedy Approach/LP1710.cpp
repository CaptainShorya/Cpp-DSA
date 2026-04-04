//Maximum Units of a Truck 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public: //TC = O(nlogn) & Space = O(sorting algo)
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        auto cmp = [](vector<int>& a, vector<int>& b){
            return a[1] > b[1]; //Descending Order via 2nd element
        };
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        int maxUnits = 0;
        for(int i=0; i<boxTypes.size(); i++){
            if(boxTypes[i][0] <= truckSize){
                maxUnits += boxTypes[i][0]*boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }else{
                maxUnits += truckSize*boxTypes[i][1];
                truckSize = 0;
                break;
            }
        }
        return maxUnits;
    }
};
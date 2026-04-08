// Gas Station
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalCost=0, totalGas =0;
        for(int i=0; i<gas.size(); i++){
             totalCost += cost[i];
             totalGas += gas[i];
        }
        if(totalGas < totalCost) return -1;
        int fuel = 0;
        int start = 0;
        for(int i=0; i<gas.size(); i++){
            fuel += gas[i] - cost[i];
            if(fuel < 0){
                start = i+1;
                fuel = 0;
            }
        }
        return start;
    }
};
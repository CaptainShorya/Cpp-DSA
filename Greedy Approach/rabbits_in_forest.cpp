//Rabbits in Forest
#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int numRabbits(vector<int>& answers) { // TC & SC = O(n)
        unordered_map<int,int> mpp;
        int ans =0;
        for(int num : answers){
            if(!mpp.count(num+1)){ //True if key does not exist
                ans += num+1;  // We started a new group 
            }
            mpp[num+1]++; //Insert in each group
            if(num+1 == mpp[num+1]){ //Checking if key == value
                mpp.erase(num+1);
            }
        }
        return ans;
    }
};
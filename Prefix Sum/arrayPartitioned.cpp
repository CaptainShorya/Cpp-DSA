#include <iostream>
#include <vector>
using namespace std;

//Check if array can be partitioned into 2 continuous arrays of equal Sum.

int main(){
    vector<int> nums = {1,2,2,1};
    //Formation of prefix sum
    for(int i=1; i<nums.size(); i++){
        nums[i] += nums[i-1];
    }
    // TC = O(n) and SC = O(1)

    //Check if any x exists where Sum(0 to x) = Sum(x+1 to n-1)
    int idx = -1;
    for(int i=0; i<nums.size();i++){
        if(2*nums[i] == nums[nums.size()-1]){
            idx = i;
            break;
        }
    }
    if(idx!=-1) cout << "It can be partitioned at index : "<< idx<< endl;
    else cout <<"It can not be partitioned." << endl;
}

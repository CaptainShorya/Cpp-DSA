#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
using namespace std;

//Majority Element -> Find elements that appear more than n/3 times

void majorityElement(vector<int> nums){//For all practical cases, we consider TC : O(n) of this code 
    int n = nums.size();
    unordered_map<int,int> mpp; // key -> element , freq -> value

    for(int i=0; i<n; i++){ //Big O(n) loop
        if(mpp.count(nums[i])){
            mpp[nums[i]]++;
        }else{
            mpp[nums[i]] = 1;
        }
    }

    //Worst case -> Saare element ki frequency 1 ho 
    for(pair<int,int> p : mpp){ // Big O(n) loop
        if(p.second > (n/3)){
            cout << p.first << " ";
        }
    }
    cout << endl;
}

int main(){
    vector<int> nums = {1,3,2,5,1,3,1,5,1};
    vector<int> nums2 = {1,2};

    majorityElement(nums);
    majorityElement(nums2);

    return 0;
}
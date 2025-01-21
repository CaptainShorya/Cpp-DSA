#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

int countDistinct(vector<int> nums){
    unordered_set<int> set;

    for(int i=0; i<nums.size(); i++){
        set.insert(nums[i]);
    }

    cout << "Numbers are : ";

    for(auto el : set){
        cout << el << " ";
    }
    cout << endl;

    return set.size();
}

int main(){
    vector<int> nums = {4,3,2,5,6,7,3,4,2,1};

    cout << "Total Count : " << countDistinct(nums) << endl;
    return 0;
}
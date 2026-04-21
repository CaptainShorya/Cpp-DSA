// LP976. Largest Perimeter Triangle

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=nums.size()-1; i>=2; i--){
            int s1 = nums[i];
            int s2 = nums[i-1];
            int s3 = nums[i-2];
// A triangle cannot be formed if the sum of the two shorter sides is less than or equal to the longest side 
            if((s2+s3) > s1 ){
                return s1+s2+s3;
            }
        }
        return 0;
    }
};
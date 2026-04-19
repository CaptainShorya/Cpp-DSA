//1855. Maximum Distance Between a Pair of Values
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int j=0;
        int i=0;
        while(i < nums1.size() && j < nums2.size()){
            if(i <= j ){
                if(nums1[i] <= nums2[j]){
                    ans = max(ans,j-i);
                    j++;
                }else{
                    i++;
                }
            }else{
                j++;
            }
        }
        return ans;
    }
};
#include <iostream> 
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

//Lp 3761

class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int ans = INT_MAX;
        unordered_map<int, int> mpp; // Reversed Number : Index
        int n = nums.size();

        for(int i=0; i<n; i++){
            int num = nums[i];
            int revNum = 0;
            // Reverse the number
            while(num > 0){
                int lastDigit = num%10;
                revNum = revNum*10 + lastDigit;
                num = num/10;
            }
            // If current number matches the reverse of a previously seen number, update minimum distance
            if(mpp.count(nums[i])){
                ans = min(ans,abs(i-mpp[nums[i]]));
            }
            //Insert reversed Number into map
            mpp[revNum] = i;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

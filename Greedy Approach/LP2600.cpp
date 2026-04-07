#include <iostream>
using namespace std;

class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        if(k == 0) return 0;
        int ans = 0;
        while( k != 0){
            if(numOnes != 0){
                ans += 1;
                numOnes--;
            }else if(numZeros != 0){
                numZeros--;
            }else if(numNegOnes !=0){
                numNegOnes--;
                ans += -1;
            }
            k--;
        }
        return ans;
    }
};
#include <iostream> 
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

int largestSubArrayLengthwithSum0(vector<int> vec){ //Near about TC : O(n)
    unordered_map<int,int> mpp; //Stores sum upto index <sum,idx>
    int sum = 0;
    int ans = 0;
    for(int j=0; j<vec.size(); j++){ 
        sum += vec[j];
        if(mpp.count(sum)){ //TC : O(1)
            int currLen = j - mpp[sum];
            ans = max(ans,currLen);
        }else{
            mpp[sum] = j;
        }
    }
    return ans;
}

int main(){
    vector<int> vec = {15,-2,2,-8,1,7,10};

    cout << largestSubArrayLengthwithSum0(vec) << endl;
    return 0;
}
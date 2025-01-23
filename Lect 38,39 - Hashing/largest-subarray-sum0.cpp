#include <iostream> 
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

int largestSubArrayLength(vector<int> vec){ //Near about TC : O(n)
    unordered_map<int,int> mpp; //Stores sum upto index <sum,idx>
    int sum = 0;
    int ans = 0;
    for(int i=0; i<vec.size(); i++){ 
        sum += vec[i];
        if(mpp.count(sum)){ //TC : O(1)
            int currLen = i - mpp[sum];
            ans = max(ans,currLen);
        }else{
            mpp[sum] = i;
        }
    }
    return ans;
}

int main(){
    vector<int> vec = {15,-2,2,-8,1,7,10};

    cout << largestSubArrayLength(vec) << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> pairSum(vector<int> vec, int target){
    vector<int> ans = vec;
    int st=0 , end = vec.size()-1;
    sort(vec.begin(),vec.end());
    // vector<int> ans;
    while(st<end){
            int currSum = vec[st] + vec[end];
            if(currSum == target){
                ans.push_back(st);
                ans.push_back(end);
                return ans;
            }
            else if(currSum > target){
                end--;
            }
            else{
                st++;
            }
    }
    return ans;
}

int main(){
    vector<int> vec = {3,2,4};
    int target = 6;
    int size = vec.size();          
    vector<int> ans = pairSum(vec,target);
    cout <<ans[0]<<","<<ans[1]<<endl;
    return 0;
}
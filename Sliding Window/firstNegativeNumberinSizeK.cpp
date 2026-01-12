#include <iostream>
#include <vector>
using namespace std;

//First Negative Number in Window Size k

int main(){
    vector<int> vec = {2,-3,4,4,-7,-1,4,-2,6};
    int n = vec.size();
    int k = 3;
    vector<int> ans(n-k+1);
    int neg = 0; //First negative index
    while(vec[neg] > 0){
        neg++;
    }

    int i = 0; 
    int j = k-1;
    while(j< n){
        if(neg >= i && neg <= j){
            ans[i] = vec[neg];
            i++;
            j++;
        }
        else{
            neg++;
            while(vec[neg] > 0) neg++;
        }
    }
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
}
#include <iostream>
#include <vector>
using namespace std;

void subset(int arr[], vector<int> ans, int n, int idx){ 
    if(n == idx){
        for(int i=0; i<ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    }
    subset(arr,ans,n,idx+1);
    ans.push_back(arr[idx]);
    subset(arr,ans,n,idx+1);
}

int main(){
    int arr[] = {1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    subset(arr,{},n,0);
}
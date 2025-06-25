#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    //Given 
    int arr[10] = {0,-1,-2,3,4,-5,6,4,7,-8};
    int k = 3;

    //Procedure
    vector<int> ans;
    int s = sizeof(arr)/sizeof(arr[0]);
    queue<int> q;

    for(int i=0; i<s; i++){
        if(arr[i] < 0) q.push(i);
    }

    int i = 0; //iterator for while loop
    while(i < s-k+1){
        while(q.size() > 0 && q.front() < i) q.pop();
        if(q.size() == 0 || q.front() >= i+k) ans.push_back(0);
        else ans.push_back(arr[q.front()]);
        i++;
    }

    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
    int arr[8] = {3,1,2,5,4,6,2,3};
    int ans[8];
    int size = sizeof(arr)/sizeof(arr[0]);

    // pop,ans,push & reverse traverse
    stack<int> st;
    ans[size-1] = -1;
    st.push(arr[size-1]);

    for(int i=size-2; i>=0; i--){
        // pop all the elements present in stack which are smaller than arr[i]
        while(st.size() > 0 && st.top() <= arr[i]) st.pop();

        //mark answer in ans array
        if(st.size() == 0) ans[i] = -1;
        else ans[i] = st.top();

        // push ith index element in stack
        st.push(arr[i]);
    }

    for(int i=0; i<size; i++){
        cout << ans[i] << " ";
    }
    cout << endl;

}
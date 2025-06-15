#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
    int arr[8] = {3,1,2,5,4,6,2,3};
    int ans[8];
    int size = sizeof(arr)/sizeof(arr[0]);

    // pop,ans,push & traverse
    stack<int> st;
    ans[0] = -1;
    st.push(arr[0]);

    for(int i=1; i<size; i++){
        while(st.size() > 0 && st.top() <= arr[i]) st.pop();

        if(st.size() == 0) ans[i] = -1;
        else ans[i] = st.top();

        st.push(arr[i]);
    }

    for(int i=0; i<size; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}
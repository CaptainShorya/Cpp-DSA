#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

//Hint -> NSE AND PSE

int main(){
    int arr[6] = {2,1,5,6,2,3};
    int nsi[6];
    int n = sizeof(nsi) / sizeof(arr[0]);
    stack<int> st;

    nsi[n-1] = n;
    st.push(n-1);

    //Next Smaller Element's Index Array
    for(int i=n-2; i>=0; i--){
        while(st.size() > 0 && arr[st.top()] >= arr[i]) st.pop();
        if(st.size() == 0) nsi[i] = n;
        else nsi[i] = st.top();
        st.push(i);
    }

    //Previous Smaller Element's Index Array
    int psi[n];
    stack<int> gt;

    psi[0] = -1;
    st.push(0);

    for(int i=1; i<=n-1; i++){
        while(gt.size() > 0 && arr[gt.top()] >= arr[i]) gt.pop();
        if(gt.size() == 0) psi[i] = -1;
        else psi[i] = gt.top();
        gt.push(i);
    }

    int maxArea = 0;
    for(int i=0; i<n; i++){
        int height = arr[i];
        int breadth = nsi[i] - psi[i] - 1;
        int area = height * breadth;
        maxArea = max(area,maxArea);
    }
    cout << maxArea << endl;
}
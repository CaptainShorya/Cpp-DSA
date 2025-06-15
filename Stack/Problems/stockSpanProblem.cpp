#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

//Interview asked question 

int main(){
    int arr[8] = {100,80,60,81,70,60,75,85};
    int pgIdx[8]; //Previous Greater Index(Need not to push previous greater element this time)
    int size = sizeof(arr)/sizeof(arr[0]);

    stack<int> st; // Here, int is the index of previous greater element
    pgIdx[0] = -1; //Default Given
    st.push(arr[0]);

    for(int i=0; i<size; i++){
        while(st.size() > 0 && arr[st.top()] <= arr[i]) st.pop();

        if(st.size() == 0) pgIdx[i] = -1;
        else pgIdx[i] = st.top();

        pgIdx[i] = i - pgIdx[i];

        st.push(i);
    }

    for(int i=0; i<size; i++){
        cout << pgIdx[i] << " ";
    }
}
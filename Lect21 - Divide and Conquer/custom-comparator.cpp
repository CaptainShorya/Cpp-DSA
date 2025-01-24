#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Ascending as per 1st and descending as for same 
bool should_i_swap(pair<int,int> a, pair<int,int> b){
    if(a.first != b.first){
        if(a.first > b.first) return true; //a.first bda to true deyo yani swap hoga mtlb bda vala peeche jayega 
        return false;
    }else{
        if(a.second < b.second) return true; // b.second bda to true deyo yani swap hoga mtlb bda vala aage jayega 
        return false;
    }
}

//Ascending as per 1st and descending for same number in 1st
bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first != b.first){
        // if(a.first > b.first) return false; 
        // return true;

        //Easy way to write
        return a.first < b.first;
    }else{
        // if(a.second < b.second) return false;
        // return true;

        //Easy way to write
        return a.second > b.second; 

    }
}

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);

    for(int i=0; i<n; i++){
        cin >> a[i].first >> a[i].second ;
    }

    // for(int i=0; i<n; i++){
    //     for(int j=i+1; j<n; j++){
    //         if(should_i_swap(a[i],a[j])){
    //             swap(a[i],a[j]);
    //         }
    //     }
    // }

    //If we replace this sorting by inbuilt sort then it show revert output 
    sort(a.begin(),a.end(), cmp); //It will swap,only if you return false -> show same behaviour as we write our own sorting algo

    for(int i=0; i<n; i++){
        cout << a[i].first << " " << a[i].second << endl;
    }
    cout << endl;
    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

//Upper and Lower Bound function

int main(){
    //Explanation for Array
    // int n = 6;
    // int a[n] = {4,5,5,25,7,8};
    // sort(a,a+n); //Mandatory step 
    // int *ptr = lower_bound(a,a+n,6); //When put 26,itself and not any greater found, so points a+n having garbage value
    // int *ptr2 = upper_bound(a+4,a+n,24); //starting from 8 and end at 25 //See difference by entering 24 and 25 value
    // if(ptr == (a+n)){
    //     cout << "Not Found";
    //     return 0;
    // }
    // cout << (*ptr) << endl;
    // cout << (*ptr2) << endl;

    //Explanation of Vector
    // int n = 6;
    // vector<int> vec = {4,5,5,25,7,8};
    // sort(vec.begin(),vec.end()); //Mandatory step 
    // //Exact Same working as array
    // auto it = lower_bound(vec.begin(),vec.end(),6); 
    // auto it2 = upper_bound(vec.begin()+4,vec.end(),24); 
    // if(it == (vec.end())){
    //     cout << "Not Found";
    //     return 0;
    // }
    // cout << (*it) << endl; //7
    // cout << (*it2) << endl; //25

    //Explanation for Sets -> by default sorted hote h
    // int n;
    // cin >> n;
    // set<int> s;
    // for(int i=0; i<n; i++){
    //     int x;
    //     cin >> x;
    //     s.insert(x);
    // }
    // auto it = s.lower_bound(25); //TC : O(logN)
    // cout << *it << endl; // 26

    //Explanation for Map
    map<int,int> mpp;
    mpp[4] = 1;
    mpp[6] = 2;
    auto it = mpp.lower_bound(5); //for 8, it points to mpp.end()
    cout << it->first << endl;
    return 0;
}
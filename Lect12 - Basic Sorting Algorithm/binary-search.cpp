#include <iostream>
#include <vector>
using namespace std;

int recursiveBinCall(vector<int> vec, int low, int high, int target){
    //Base Case
    if(low > high){
        return -1;
    }
    int mid = (low + high)/2;

    if(vec[mid] == target){
        return mid;
    }
    else if(vec[mid] > target){
        return recursiveBinCall(vec,low,mid-1,target); //If we don't use return it never reaches main(), because recursiveBinCall fn did not return anything.
    }else{
        return recursiveBinCall(vec,mid+1,high,target);
    }
    
}

int main(){
    vector<int> vec = {3,4,6,7,9,12,16,17};
    int n = vec.size();

    int low = 0;
    int high = n -1;
    int target = 13;

    cout << recursiveBinCall(vec,low,high,target);
    return 0;
}
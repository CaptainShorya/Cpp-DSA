#include <iostream>
#include <vector>
using namespace std;

int firstOccurence(vector <int>arr,int target, int i){
    //Base case 
    if(i == arr.size()){
        return -1;
    }
    //Kaam
    if(arr[i] == target){
        return i;
    }
    //Inner/Next function call
    return firstOccurence(arr,target,i+1);
}

int main(){
    vector <int>arr = {1,2,3,5,5};
    int target = 5;
    cout << firstOccurence(arr,target,0) << endl;
}
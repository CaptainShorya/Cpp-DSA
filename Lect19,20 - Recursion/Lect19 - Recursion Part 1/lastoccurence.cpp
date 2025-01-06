#include <iostream>
#include <vector>
using namespace std;

static int occurence = -1;

int lastOccurence(vector<int>vec, int target, int i){

    //Base case
    if(i == vec.size()){
        return occurence;
    }

    //Kaam
    if(vec[i] == target){
        occurence = i;
    }

    //inner function call
    return lastOccurence(vec,target,i+1);
}

int main(){
    vector<int> arr = {1,2,3,3,4};
    int target = 5;
    cout << lastOccurence(arr,target,0);
    return 0;
}
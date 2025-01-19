#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


int main(){
    int arr[7] = {1,2,7,11,15,5,9};
    int size = 7;
    int target = 9;
    
    unordered_map<int,int> mpp; //key -> arr[i] and value -> idx
    for(int i=0; i<size; i++){
        int compliment = target - arr[i];
        if(mpp.count(compliment) == 1){
            cout << mpp[compliment] << "," << i << endl;
        }else{
            mpp[arr[i]] = i;
        }
    }

}
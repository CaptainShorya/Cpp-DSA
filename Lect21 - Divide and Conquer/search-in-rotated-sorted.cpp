#include <iostream>
using namespace std;

//Search in Rotated sorted
int search(int arr[], int si, int ei, int target){ // O(logn)
    //Base case 
    if(si > ei){ //equal to is not used bcz for si = ei BS would be performed(eg -> take tar = 2 and think)
        return -1; //Target does not exist
    }

    int mid = si + (ei-si)/2;

    if(arr[mid] == target){
        return mid;
    }

    //Check on which line mid is lying
    if(arr[si] <= arr[mid]){ //L1
        //Case a
        if(arr[si] <= target && target < arr[mid]){
            //left half
            search(arr,si,mid-1,target);
        }
        //Case b
        else{
            //right half
            search(arr,mid+1,ei,target);
        }
    }else{ // L2
        //Case c
        if(arr[mid] < target && target <= arr[ei]){
            //right half
            search(arr,mid+1,ei,target);
        }
        //Case d
        else{
            //left half
            search(arr,si,mid-1,target);
        }
    }
}


int main(){
    int arr[7] = {4,5,6,7,0,1,2};
    int n = 7;
    int tar = 10;

    cout << "Idx : " << search(arr,0,n-1,tar) << endl;

    return 0;
}
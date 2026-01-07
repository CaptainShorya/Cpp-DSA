#include <iostream>
#include <vector>
using namespace std;

// Finding subarrays in an array

//Iterative Method 
void iterative_finding_subarray(vector<vector<int>> subarray,vector<int> vec ){
    for(int i=0; i<vec.size(); i++){
        vector<int> vec1;
        for(int j=i; j<vec.size(); j++){
            vec1.push_back(vec[j]);
            subarray.push_back(vec1);
        }
    }
    for(int i=0; i<subarray.size(); i++){
        for(int j=0; j<subarray[i].size(); j++){
            cout << subarray[i][j] << " ";
        }
        cout << endl; 
    }
}

// Recursive Method
void recursive_finding_subarray(vector<int> subarray,vector<int>vec, int index){
    //Everytime push_back is occuring, so no use of pass by reference.
    if(index==vec.size()){
        for(int i=0; i<subarray.size(); i++){
            cout<< subarray[i] << "";
        }
        cout << endl;
        return;
    }
    //Exclude
    recursive_finding_subarray(subarray,vec,index+1);
    //Include
    if(subarray.size() == 0 || vec[index-1] == subarray[subarray.size()-1]){
        subarray.push_back(vec[index]);
        recursive_finding_subarray(subarray,vec,index+1);
    }
    
}

int main(){
    vector<vector<int>> subarray;
    vector<int> vec ={1,2,3,4};
    
    // iterative_finding_subarray(subarray,vec);
    recursive_finding_subarray({},vec,0);
}
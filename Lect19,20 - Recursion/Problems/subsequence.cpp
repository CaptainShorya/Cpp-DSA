#include <iostream>
#include <vector>
using namespace std;

//Print all increasing subsequence of length k from the first n natural numbers.

void subsequence(vector<int>vec,vector<vector<int>>& subsequence_array, vector<int> temp_vec, int i, int k){
    if(temp_vec.size() == k){
        subsequence_array.push_back(temp_vec);
        return;
    }
    if(i == vec.size()) return; //Stopping condition
    if(temp_vec.size() + (vec.size()-i) < k) return; //Time complexity better
    //Even if I take ALL remaining elements, I still cannot reach length k. So there is no point continuing this recursion branch.
    subsequence(vec,subsequence_array,temp_vec,i+1,k); //Exclude
    temp_vec.push_back(vec[i]);
    subsequence(vec,subsequence_array,temp_vec,i+1,k); //Include
    
}

int main(){
    vector<int> vec;
    vector<vector<int>> subsequence_array;
    int n = 5; //First n natural number
    int k = 3;
    int index = 0;
    for(int i=1; i<=n; i++){
        vec.push_back(i);
    }
    subsequence(vec,subsequence_array,{},index,k);
    for(int i=0;i<subsequence_array.size(); i++){
        for(int j=0; j<k; j++){
            cout << subsequence_array[i][j] << " ";
        }
        cout << endl;
    }
}
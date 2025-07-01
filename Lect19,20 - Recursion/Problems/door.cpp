#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

// 0 -> Denotes that particular gate is closed
// 1 -> Denotes that particular gate is open

//Trick -> The gate which remain open have odd number of multiples,which occured only in perfect square(eg. 1,4,9,16)

int main(){
    vector<int> vec(100,0);
    for(int i=1; i<=vec.size(); i++){
        for(int j=1; j<=ceil(i/2); j++){
            if(i % j == 0){
                if(vec[i-1] == 0) vec[i-1] = 1;
                else vec[i-1] = 0;
            }
        }
    }
    int count = 0;
    for(int i=0; i<vec.size(); i++){
        if(vec[i] == 0){
            count++;
            cout << i+1 << " ";
        }
    }
    cout << endl;
    cout << "Number of gate open = " << count << endl;
}
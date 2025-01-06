#include <iostream>
using namespace std;

bool search(int matrix[][4],int n,int m,int key){
    int i = 0,j = m-1;

    //O(n+m)
    while(i<n && j>=0){
        int cell = matrix[i][m-1];
        if(matrix[i][j] == key){
            cout << "Found at cell("<<i <<" "<<j <<")\n";
        } else if(cell < key){
            //down -> row++
            i++;
        }else{
            //left -> col--
            j--;
        }
    }
    cout<<"Key not found"<<endl;
    return false;
}

int main(){
    int matrix[4][4] = {{10,20,30,40},{15,25,35,45},{27,29,37,48},{32,33,39,50}};
    int found = search(matrix,4,4,33);
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> vec = {0,0,0,1};
    int k = 2;
    int n =vec.size();
    int flips = 0, i =0, j =0;
    int maxLen = INT16_MIN;
    int len = 0;
    while(j < n){
        if(vec[j] == 1) j++;
        else{ // vec[j] == 0
            if(flips < k){
                flips++;
                j++;
            }else{ //flips == k
                //calculate a length 
                len = j-i;
                maxLen = max(maxLen,len);
                // i ko just uske aage vale zero se ek idx aage le jayo
                while(vec[i] != 0) i++;
                // after this 100% nums[i] = 0
                i++; // Ab vali window ki length nhi nikalenge kiyuki vo aur choti rhega
                j++;
            }
        }
        
    }
    //when j > n, then we have to do another len check  
    len = j-i;
    maxLen = max(maxLen,len);
    cout << maxLen << endl;
}
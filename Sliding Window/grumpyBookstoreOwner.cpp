#include <iostream>
#include <vector>
using namespace std;

//Hint -> Find the window having "most loss of satisfaction" that is 
// != window with "least satisfaction"

int maxSatisfied(vector<int> customers, vector<int> grumpy, int minutes){
    int n = customers.size();
    int i = 1;
    int j = minutes;
    int maxIdx = 0;
    int curr_loss = 0;
    int maxSatisfied = 0;
    //Count only grumpy Customers
    for(int k=0; k<minutes; k++){
        if(grumpy[k]) curr_loss += customers[k];
    }
    int maxLos = curr_loss;
    while(j<n){
        if(grumpy[j]) curr_loss = curr_loss + customers[j];
        if(grumpy[i-1]) curr_loss = curr_loss - customers[i-1];
        if(curr_loss > maxLos){
            maxIdx = i;
            maxLos = curr_loss;
        }
        j++;
        i++;
    }
    //filling 0s in the grumpy array window
    for(int a=maxIdx; a<maxIdx+minutes; a++){
        grumpy[a] = 0;
    }
    // sum of satisfaction
    for(int b=0; b<n; b++){
        if(!grumpy[b]) maxSatisfied += customers[b];
    }
    return maxSatisfied;
}

int main(){
    vector<int> customers = {9,10,4,5};
    vector<int> grumpy = {1,0,1,1};
    int minutes = 1; //window

    cout << maxSatisfied(customers,grumpy,minutes);
}
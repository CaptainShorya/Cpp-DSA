#include <iostream>
using namespace std;

//Buy and Sell Stocks
void maxProfits(int *prices, int n){
    //S1 -> Findout Bestbuy
    // int bestBuy[n]; //It is not possible to do dynamic sizing of array inside a function

    int bestBuy[10000]; //A/C to leetcode, max possible value of n is 10 to power 4
    bestBuy[0] = INT32_MAX;
    for(int i=1; i<n; i++){
        bestBuy[i] = min(bestBuy[i-1],prices[i-1]);
    }

    //S2 -> Profit
    int maxProfit = 0;
    for(int i=0; i<n; i++){
        int currProfit = prices[i] - bestBuy[i];
        maxProfit = max(maxProfit,currProfit);
    }
    //O(n+n) = O(2n) = O(n) -> Time Complexity
    cout<<"MaxProfits : "<<maxProfit<<endl;
}


int main(){
    int arr[] = {7,6,4,3,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    maxProfits(arr,n);
    return 0;
}
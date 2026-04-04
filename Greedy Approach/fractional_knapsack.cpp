#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Custom Comparator
bool cmp(pair<int,int>& a, pair<int,int>& b){
    // return a < b -> if true then a comes before b => ascending order
    // return a > b -> if true then descending order

    // Sort by decreasing (value/weight) ratio → higher ratio gets priority
    double r1 = (a.first*1.0) / (a.second*1.0);
    double r2 = (b.first*1.0) / (b.second*1.0);
    return r1 > r2; //Decreasing Order
}

double fractionalKnapsack(vector<int>& profits, vector<int>& weights, int W, int n){
    vector<pair<int,int>> arr;
    for(int i=0; i<n; i++){
        arr.push_back({profits[i],weights[i]});
    }
    sort(arr.begin(),arr.end(),cmp);
    double result = 0;
    for(int i=0; i<n; i++){
        if(arr[i].second <= W){
            result += arr[i].first;
            W -= arr[i].second;
        }
        else{ //Fractional Adjustmnet 
            result += ((arr[i].first*1.0)/(arr[i].second*1.0))*W;
            W = 0;
            break;
        }
    }
    return result;
}

int main(){
    vector<int> profits = {60,100,120};
    vector<int> weights = {10,20,30};
    int W = 50;
    int n = 3;
    cout << "Frational Knapsack(final output) = " << fractionalKnapsack(profits,weights,W,n) <<endl;
    return 0;
}
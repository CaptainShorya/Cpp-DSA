#include <iostream>
using namespace std;

//Tiling Problem -> Optimized Solution will be studied in DP , Asked in amazon and google

int tilingProblem(int n){ //2xn
    if( n == 0 || n == 1){
        return 1;
    }

    //vertical
    int ans1 = tilingProblem(n-1); // 2x(n-1)

    //horizontal
    int ans2 = tilingProblem(n-2); // 2x(n-2)

    return ans1 + ans2;
}

int main(){
    int n;
    cout << "Enter width of floor : " ;
    cin >> n;
    int waysOfPlacingTiles = tilingProblem(n);
    cout << "Total No of ways = " << waysOfPlacingTiles << endl;
    return 0;
}
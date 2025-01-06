#include <iostream>
using namespace std;
int main(){
    //Q1
    //Outer Loop
    // int n = 5;
    // for(int i=1; i<=n; i++){
    //     if(i%2 != 0){
    //         int a = 1;
    //         for(int j=1; j<=i; j++){
    //             cout<<a<<" ";
    //             if(a){
    //                 a = 0;
    //             }else{
    //                 a = 1;
    //             }
    //     }
    //     }else{
    //         int b = 0;
    //         for(int k=1; k<=i; k++){
    //             cout<<b<<" ";
    //             if(b){
    //                 b = 0;
    //             }else{
    //                 b = 1;
    //             }
    //         }
    //     }
    //     cout<<endl;
    // }

    //Q2
    // int n = 4;
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n-i+1; j++){
    //         cout<<" ";
    //     }
    //     int k = 1;
    //     while(k<=5){
    //         cout<<"*";
    //         k++;
    //     }
    //     cout<<endl;
    // }

    //Q3
    int n = 5;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=(n-i); j++){
            cout<<" "<<" ";
        }
        for(int k=i; k>=1; k--){
            cout<<k<<" ";
        }
        
        for(int l=1; l<i; l++){
            cout<<l+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}
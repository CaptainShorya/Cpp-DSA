#include <iostream>
using namespace std;
int main(){ //Dry Run code to build better understanding 
    
    //Nested Loops
    // for (int i =1; i<=4; i++){ //Number of Rows
    //     for(int j=1; j<=4; j++){ //Number of columns in each row 
    //         cout<<i<<" ";
    //     }
    //     cout<<endl;
    // }
    //Output
    //1 1 1 1
    //2 2 2 2 
    //3 3 3 3
    //4 4 4 4

    //Star Pattern
    // int n = 4;
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=i; j++){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }
    //Output
    //*
    //**
    //***
    //****

    //Inverted Star Pattern
    // int n = 4;
    // for(int i=1; i<=n; i++){
    //     for(int j=n; j>=i; j--){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }
    //Approach 2
    // int n = 4;
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=(n-i+1); j++){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }
    //Output
    //**** 
    //***
    //**
    //*

    //Half Pyramid Pattern
    // int n = 4;
    // for(int i=1; i<=4; i++){
    //     for(int j=1; j<=i; j++){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }

    //Character Pyramid Pattern
    // int n = 4;
    // char ch = 'A';
    // for(int i=1; i<=(n); i++){
    //     for(int j=1;j<=i; j++){
    //         cout<<ch++; //Post Increment -> First Print then update the value
    //         // ch++;
    //     }
    //     cout<<endl;
    // }

    //Hollow Rectangle Pattern
    // int n = 4;
    // for(int i=1; i<=n;i++){
    //     for(int j=0; j<=n; j++){
    //         if((i!=1 && i!=n) && (j!=0 && j!=n)){
    //             cout<<" ";
    //             continue;
    //         }
    //         cout<<'*';
    //     }
    //     cout<<endl;
    // }

    //Another Approach(Told By Mam)
    // int n = 4;
    // for(int i=1; i<=n; i++){
    //     cout<<"*";//First
    //     for(int j=1; j<=(n-1); j++){
    //         if(i==1 || i==n){
    //             cout<<"*";
    //         }else{
    //             cout<<" ";
    //         }
    //     }
    //     cout<<"*"<<endl;//End
    // }

    //Inverted and Rotated Half Pattern
    // int n = 4;
    // for(int i=1; i<=n; i++){
    //     //spaces
    //     for(int j=1; j<=(n-i); j++){
    //         cout<<" ";
    //     }
    //     //stars
    //     for(int k=(n-i); k<n; k++){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }

    //Floyd's Triangle Pattern
    // int n = 5;
    // int num = 1;
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=i; j++){
    //         cout<<num++<<" ";
    //     }
    //     cout<<endl;
    // }
    //Output
    // 1 
    // 2 3 
    // 4 5 6 
    // 7 8 9 10 
    // 11 12 13 14 15 

    //Diamond Pattern -> Split them into 2 triangle
    //Upper Triangle
    // int n = 4;
    // for(int i=1; i<=n; i++){
    //     for(int y=1; y<=(n-i); y++){
    //         cout<<" ";
    //     }
    //     for(int z=1; z<=(2*i-1); z++){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }
    //Lower Triangle
    // for(int j=n; j>=1; j--){
    //     for(int a=1; a<n-j+1; a++){
    //         cout<<" ";
    //     }
    //     for(int b=1; b<=(2*j-1); b++){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }
    //Output
    //     *
    //    ***
    //   *****
    //  *******
    //  *******
    //   *****
    //    ***
    //     *

    //Butterfly Pattern
    int n = 4;
    //Upper Side
    for(int i=1; i<=n; i++){
        for(int a=1; a<=i; a++){
            cout<<"*";
        }
        for(int b=2*i; b<2*n; b=b+1){
            cout<<" ";
        }
        for(int c=1; c<=i; c++){
            cout<<"*";
        }
        cout<<endl;
    }
    //Lower Side
    for(int j=4; j>=1; j--){
        for(int x=1; x<=j; x++){
            cout<<"*";
        }
        for(int y=2*n; y>2*j; y--){
            cout<<" ";
        }
        for(int z=1; z<=j; z++){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}
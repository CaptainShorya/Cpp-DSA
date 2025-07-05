#include<iostream>
using namespace std;

//Pre In Post Concept Used Here
//For 1 -> 111 , 2 -> 211121112 , 3 -> 321112111232111211123 .... goes on

void zigZag(int val){
    if(val == 0) return;
    cout << val; //Pre 
    zigZag(val-1);
    cout << val; //In
    zigZag(val-1);
    cout << val; //Post
}

int main(){
    zigZag(2);
}
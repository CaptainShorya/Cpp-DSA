#include <iostream>
#include <vector>
using namespace std;

//Making our Queue Class using Array(Array IMplementation of Queue)

class Queue{
public:
    int f;
    int b;
    int s;
    vector<int> arr; // In starting, vector is empty

    //Constructor
    Queue(int sz){
        f = 0;
        b = 0;
        s = 0;
        vector<int> v(sz);
        arr = v; //Now vector having size s
    }

    void push(int val){
        if(b == arr.size()){
            cout << "Queue is Full" << endl;
            return;
        }
        arr[b] = val;
        b++;
        s++;
    }

    void pop(){
        if(s == 0) return;
        f++;
        s--;
    }

    int front(){
        if(s == 0){
            cout << "Queue is EMPTY" << endl;
            return -1;
        }
        return arr[f];
    }
    int back(){
        if(s == 0){
            cout << "Queue is EMPTY" << endl;
            return -1;
        }
        return arr[b-1];
    }

    int size(){
        return b - f;
    }

    bool empty(){
        if(s == 0) return true;
        else return false;
    }

    void display(){
        for(int i=f; i<b; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    //I want to set size of Queue at the time of making object of Queue class
    Queue q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.display();
    q.push(50);
    q.push(60); // Queue is FULL since only 5 size array is present.
    q.display();
    q.pop();
    q.display();
}

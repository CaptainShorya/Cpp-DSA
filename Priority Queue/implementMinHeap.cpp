#include <iostream>
using namespace std;

class minHeap{
public:
    int arr[50];
    int idx;
    minHeap(){
        idx = 1;
    }
    int top(){
        return arr[1];
    }
    void push(int x){
        arr[idx] = x;
        int i = idx;
        idx++;
        while(i!=1){
            if(arr[i] < arr[i/2]){
                swap(arr[i],arr[i/2]);
                i = i/2;
            }
            else break;
        }
    }
    int size(){
        return idx-1;
    }
    void pop(){
        if(idx == 1){
            cout << "Heap is Empty" << endl;
            return;
        }
        idx--;
        arr[1] = arr[idx];
        int i = 1;
        while(true){
            int left = 2*i;
            int right = 2*i + 1;
            //idx - 1 denotes new size after popping the element.
            if(left > idx-1) break;

            if(right > idx-1){
                if(arr[i] > arr[left]){ //Since right does not exist, check whether parent > left children
                    swap(arr[i],arr[left]);
                    i = left;
                }
                break;
            }

            if(arr[left] < arr[right] ){
                if(arr[i] > arr[left]){ //Check whether parent greater than child,otherwise break
                    swap(arr[i],arr[left]);
                    i = left;
                }
                else break;
            }
            else {
                if(arr[i] > arr[right]){ //Check whether parent greater than child,otherwise break
                    swap(arr[i],arr[right]);
                    i = right;
                }
                else break;
            }  
        }
    }

    void display(){
        for(int i=1; i<idx; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    minHeap pq;
    pq.push(10);
    pq.push(20);
    pq.push(11);
    cout << pq.top() << endl;
    cout << pq.size() << endl;
    pq.push(2);
    cout << pq.top() << endl;
    cout << pq.size() << endl;
    pq.display();
    pq.pop();
    cout << pq.top() << endl;
    cout << pq.size() << endl;
    pq.display();
}
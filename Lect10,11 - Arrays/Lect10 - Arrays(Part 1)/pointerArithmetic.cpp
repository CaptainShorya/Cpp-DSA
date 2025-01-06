#include <iostream>
using namespace std;
int main(){
    
    int a = 10;
    int *aptr = &a;
    
    //Increment and Decrement Operator
    cout<<aptr<<endl; //0x61ff08
    aptr++; // 4 for int
    cout<<aptr<<endl; //0x61ff0c
    aptr--;
    cout<<aptr<<endl; //0x61ff08

    //Addition and Subtraction of Constants
    int b = 10;
    int *bptr = &b;

    cout<<bptr<<endl; //0x61ff00
    bptr = bptr + 3;
    cout << bptr - 3 << endl; //0x61ff00

    //Addition and Subtraction of Pointers
    int c = 10;
    int *ptr1 = &c;
    int *ptr2 = ptr1 + 3;

    cout<<ptr1<<"  "<<ptr2<<endl; //0x61fef4  0x61ff00
    cout<<ptr2 - ptr1<<endl; //3

    //For arrays,
    int arr[20] = {1,2,3,4,5,6};
    int *arrptr = arr; 
    cout<<arrptr<<endl; //0x61fe9c
    int *arrptr2 = arrptr + 3;

    cout<<*arrptr<<endl; //1
    cout<<*arrptr2<<endl; //4

    cout << arrptr2 - arrptr <<endl; // 3

    //Comparsion Operator
    cout << (arrptr2 > arrptr) <<endl; //yes:true -> Output is 1
    cout << (arrptr2 < arrptr) <<endl; //no:false -> Output is 0
    cout << (arrptr == arr) <<endl; //Output is 1
    return 0;
}
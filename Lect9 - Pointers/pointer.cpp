#include <iostream>
using namespace std;
int main(){
    int a = 10;
    int *ptr = &a;

    float pi = 3.14;
    float *piptr = &pi;//pointer variable

    cout<<sizeof(ptr)<<endl;
    cout<<sizeof(piptr)<<endl;

    int **ptr2 = &ptr;//Pointer to pointer variable 
    cout<<ptr2<<" = "<<&ptr<<endl;

    cout<<&pi<<" = "<<piptr<<endl;
    cout<<&a<<" = "<<ptr<<endl;

    //Dereference operator
    int b = 2;
    int *bptr = &b;

    cout<<b<<'\n';
    cout<<*bptr<<"\n";

    *bptr = 20;
    cout<<b<<endl;

    //Null Pointer
    int *cptr = NULL;
    cout << cptr << endl;
    //We cannot dereference Null pointer it will give segmentation error
    cout << *cptr << endl;//Segmentation error
    cout<<"Bye"<<endl; //This will not get executed then 


    
    return 0;
}
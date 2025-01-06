#include <iostream>
using namespace std;

class Parent{
public:
    void show(){
        cout << "Parent class shown...\n";
    }

    virtual void hello(){
        cout << "Hello Parent\n";
    }
};

class Child : public Parent{
public:
    void show(){
        cout << "Child class shown...\n";
    }
    void hello(){
        cout << "Hello Child\n";
    }
};

int main(){
    Child ch1;
    
    Parent *ptr;

    ptr = &ch1; //Parent ka pointer is bind with child ka object  //Run Time Binding(Possible due to inheritance)
    ptr->hello(); //Virtual function
    return 0;
}

#include <iostream>
using namespace std;

class Parent{
public:
    void show(){
        cout << "Parent class shown...\n";
    }
};

class Child : public Parent{
public:
    void show(){
        cout << "Child class shown...\n";
    }
};

int main(){
    Child ch1;
    ch1.show();
    return 0;
}

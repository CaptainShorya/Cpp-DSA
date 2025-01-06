#include <iostream>
using namespace std;

class Animal{
public:
    string color;

    void eat(){
        cout << "Eat\n";
    }
    void breadth(){
        cout << "Breadth\n";
    }
};

class Mammal : public Animal{
public:
    string bloodType;

    Mammal(){
        bloodType = "Warm";
    }
};

class Dog : public Mammal{
public:
    void tailWag(){
        cout << "A dogs wag is tail\n";
    }
};

int main(){
    Dog d1;

    cout << d1.bloodType << endl;
    d1.eat();
    return 0;
}
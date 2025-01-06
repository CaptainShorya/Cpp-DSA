#include <iostream>
using namespace std;

class Animal{
public:
    string color;

    void eat(){
        cout << "Eat\n";
    }
    void breadthe(){
        cout << "Breadth\n";
    }
};

class Fish : public Animal{
public:
    int finn;

    void swim(){
        eat();
        cout << "Swim\n";
    }
};

int main(){
    Fish f1;
    f1.finn = 3;
    f1.swim();

    f1.eat();
}
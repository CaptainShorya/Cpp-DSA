#include <iostream>
#include <string>
using namespace std;

class Car{

public:
    string name;
    string color;
    int *mileage;

    Car(string name, string color){
        this->name = name;
        this->color = color;
        mileage = new int; //Dynamic Allocated
        *mileage = 12;
    }

    //Custom Copy Constructor - Used to make deep copy as shallow copy is automatically made by the compiler.
    Car(Car &original){
        cout << "Copy original to new..\n";
        name = original.name;
        color = original.color;
        mileage = new int;
        *mileage = *original.mileage;
    }
};

int main(){
    //Parameterised constructor
    Car c1("Maruti","Pink");

    //Copy Constructor
    Car c2(c1);
    cout << c2.name << endl;
    cout << c2.color << endl;

    //Deep Copy
    *c1.mileage = 10;
    cout << *c1.mileage << " != " << *c2.mileage << endl;
    return 0;
}
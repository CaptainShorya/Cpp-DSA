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

    //Destructor 
    ~Car(){
        cout << "Deleting Objects\n";
        if(mileage != NULL){
            delete mileage;
            mileage = NULL;
        }
    }
};

int main(){
    //Parameterised constructor
    Car c1("Maruti","Pink");

    cout << c1.name << endl;
    cout << c1.color << endl;
    cout << *c1.mileage << endl;
    return 0;
}
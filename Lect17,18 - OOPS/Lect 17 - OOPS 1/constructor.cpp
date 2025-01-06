#include <iostream>
#include <string>
using namespace std;

class Car{
    string name;
    string color;

public: 
    Car(){
        cout << "Constructor without params" << endl;
    }

    Car(string name, string color){
        cout << "Constructor with params"<< endl;
        this->name = name;
        this->color = color; //this->color is same as *this.color which means c1.color.
    }

    void start(){
        cout << "Car has started \n";
    }

    void stop(){
        cout << "Car has stoped \n";
    }

    //Getters
    string getName(){
        return name;
    }

};

int main(){
    Car c0; //non-parameter constructor will be called
    Car c1("Hyundai","Yellow"); //parameter constructor will be called


    cout << "Car Name : " << c1.getName() << endl;
    return 0;
}
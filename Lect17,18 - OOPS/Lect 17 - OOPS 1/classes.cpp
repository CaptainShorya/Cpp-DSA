#include <iostream>
using namespace std;

class Student{
    //properties
public: //Access Modifiers
    string name;
    float cgpa;

    //methods
    void getPercentage(){
        cout << (cgpa * 10) << endl;
    }
};

int main(){

    Student s1; //object
    cout << sizeof(s1) << endl;

    s1.name = "Shorya";
    s1.cgpa = 9;

    cout << s1.name << endl;
    cout << s1.cgpa << endl;
    s1.getPercentage();

    return 0;
}
#include <iostream>
using namespace std;

class Teacher{
public:
    int salary;
    string subject;
};

class Student{
public:
    int rollNo;
    float cgpa;
};

class TA : public Teacher, public Student{
public:
    string name;
};

int main(){
    TA ta1;

    ta1.name = "Shorya Vishnoi";
    ta1.subject = "Business";
    ta1.cgpa = 9.8;


    cout << ta1.name << endl;
    cout << ta1.cgpa << endl;
    cout << ta1.subject << endl;
    return 0;
}
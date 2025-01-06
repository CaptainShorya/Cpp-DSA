#include <iostream>
#include <string>
using namespace std;

class Student{
    //private members
    string name;
    float cgpa;
public: 
    void getPercentage(){
        cout << (cgpa * 10) << endl;
    }

    //Setters
    void setName(string nameVal){
        name = nameVal;
    }
    void setCgpa(float cgpaVal){
        cgpa = cgpaVal;
    }

    //Getters
    string getName(){
        return name;
    }
    float getCgpa(){
        return cgpa;
    }
};

int main(){

    Student s1; //object
    s1.setName("Shorya");
    s1.setCgpa(10);
    
    cout << s1.getName() << endl;
    cout << s1.getCgpa() << endl;

    return 0;
}
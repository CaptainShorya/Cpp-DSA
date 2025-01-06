#include <iostream>
using namespace std;

class Complex{
    int real;
    int complex;

public:
    //Constructor
    Complex(int r,int c){
        real = r;
        complex = c;
    }

    void showNum(){
        cout << real <<" + "<<complex << "i\n";
    }

    //Operator Overloading
    Complex operator + (Complex &obj){
        cout << this->real << endl;
        cout << obj.real << endl;
        int realRes = this->real + obj.real;
        int complexRes = this->complex + obj.complex;
        Complex c3(realRes,complexRes);
        return c3;
    }
};

int main(){
    Complex c2(3,4);
    Complex c1(1,2);
    

    c1.showNum();
    c2.showNum();

    Complex c3 = c2 + c1; //c2 reflect this and c1 reflect obj which is pass as parameter
    c3.showNum();
}
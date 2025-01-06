#include <iostream>
using namespace std;

//cout is declaraed inside std class.So we don't have to write it as std::cout 

void counter(){
    static int count = 0;
    count ++;
    cout << "Count : " << count << endl;
}


class Counter{
public:
    static int x; //Can not initialzed by 0 here in this line. //x ka declaration is here
};

int Counter::x = 0; //Static variable initialized(outside class)

int main(){

    //In function
    counter(); //1
    counter(); //2
    counter(); //3

    //In class
    Counter c1;
    Counter c2;
    Counter c3;

    cout << c1.x++ << endl; //0
    cout << c2.x++ << endl; //1 
    cout << c3.x++ << endl; //2
    return 0;
}
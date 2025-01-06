#include <iostream>
using namespace std;

//abstract class
class Shape{
public:
    virtual void draw() = 0; //Abstract function(pure virtual function)
};

class Circle : public Shape{
public:
    void draw(){
        cout << "Draw Circle\n";
    }
};

class Square : public Shape{
public:
    void draw(){
        cout << "Draw Square\n";
    }
};

int main(){
    Circle cir1;
    cir1.draw();

    Square sq1;
    sq1.draw();

    return 0;
}

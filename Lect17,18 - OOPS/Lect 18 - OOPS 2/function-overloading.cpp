#include <iostream>
using namespace std;

class Print{
public:
    void show(int x){
        cout << "int : " << x << endl;
    }

    void show(string str){
        cout << "String : " << str << endl;
    }
};

int main(){
    Print obj1;
    obj1.show(20);
    obj1.show("Shorya");
    return 0;
}
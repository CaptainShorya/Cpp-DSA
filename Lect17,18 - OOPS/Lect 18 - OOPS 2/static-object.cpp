#include <iostream>
using namespace std;

class Example{
public:
    Example(){
        cout << "Constructur\n" ;
    }

    ~Example(){
        cout << "Destructor\n" ;
    }
};


int main(){
    int a = 0;
    if(a==0){
       Example ex1; //Try this with or without static and see what happen
    }
    
    cout << "Code Ending" << endl;
    return 0;
}
#include <iostream>
using namespace std;
int main()
{
    //Calculator Using Switch Statement
    cout<<"Calulator\n";
    char opeUsed;
    int a,b;
    cout<<"Enter 1st number: ";
    cin >> a;
    cout<<"Enter 2nd number: ";
    cin >> b;
    cout<<"Operation to perform: ";
    cin >> opeUsed;

    switch(opeUsed){
        case '+': cout<<"Sum is : "<<a+b<<endl;
                    break;
        case '-': cout<<"Difference is : "<<a-b<<endl;
                    break;
        case '*': cout<<"Product is : "<<a*b<<endl;
                    break;
        case '/': cout<<"Division is : "<<a/b<<endl;
                    break;
        default: cout<<"Inavlid Operation performed";
    }

}
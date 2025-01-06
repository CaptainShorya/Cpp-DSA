#include <iostream>
#include <string>
using namespace std;
int main(){
    // string str = "hello";
    // cout << str <<endl;
    // str = "yellow";
    // cout << str << endl;
    // cout << str[2] << endl;

    // string str2;
    // getline(cin,str2,'$');
    // cout << str2 << endl;
    // cout << str2[0] << endl;

    //for loop
    // string str3 = "KedarKantha Trek";
    // for(int i=0; i<str3.length(); i++){
    //     cout << str3[i] <<endl;
    // }
    // cout << "\n";

    //for each loop - When only character is required not its index then we use this.
    // for(char ch: str3){ //char -> datatype , ch -> variable , str3 - object of string class
    //     cout << ch << endl;
    // }


    //String Member functions
    string str = "I love C++.Also C++ contains OOPS and Oops is part of C++";
    // cout << str.find("C++") << endl;
    cout << str.find("C++",16) << endl;
    cout << str.find("C++",17) << endl;

    cout << str.find("python") <<endl; //find return -1 for value which is not found in the given string
    return 0;
}
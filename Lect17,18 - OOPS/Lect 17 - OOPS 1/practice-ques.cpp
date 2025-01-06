#include <iostream>
#include <string>
using namespace std;

//Ques -> Create a user class with properties: id(private),username(public) and password(private).Its id should be initalized in a paramterised constructor and it should have a getter and setter for password.

class User{
    int id;
    string password;

public:
    User(int id){
        this->id = id;
    }
    string username;

    void setPassword(string password){
        this->password = password;
    }
    
    string getPassword(){
        return password;
    }

};

int main(){
    User u1(100);
    u1.setPassword("Shorya13");

    cout << "Password : " << u1.getPassword() << endl;
    return 0;

}
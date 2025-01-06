#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char str1[100];
    char str2[100] = "World";
    // str = "Hello"; //We cannot assign any string literal value aise into an char array.

    //function 1
    strcpy(str1,"Hello");
    // strcpy(str1,str2):

    //function 2
    strcat(str1,str2);
    cout<<str1<<endl;

    //function 3
    cout << strcmp(str1,str2) <<endl;
    
    return 0;
}
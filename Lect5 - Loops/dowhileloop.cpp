#include <iostream>
using namespace std;
int main(){
    //do-while 
    // int i = 1;
    // do{
    //     cout << i << " ";
    //     i++;
    // }while(i<3);

    //Break statement 
    // int j = 1;
    // while(j <= 10){
    //     if(j == 4){
    //         break;
    //     }
    //     cout << j <<endl;
    //     j++;
    // }
    // cout<< "Out of loop now"<<endl;

    //Qs -> WAP where user can keep entering number till they enter a multiple of 10.
    // int num;
    // cout << "Enter a number : ";
    // cin >> num;
    // while(num != 0 && num % 10 != 0){
    //     cout << "Enter a number : ";
    //     cin >> num;
    // }
    // cout << "Program Ends";

    //Another approach 

    // int n;
    // do{
    //     cout<< "Enter a number: ";
    //     cin >> n;
    //     if(n%10 == 0){
    //         break;
    //     }
    //     cout<<"You entered : "<<n<<endl;
    // }while(true);

    //continue statement
    // for(int i=0; i<=10; i++){
    //     if(i==3){
    //         continue; 
    //     }
    //     cout<<i<<endl; //skip these lines of code for i=3 and move directly to updation statement
    // }

    //Qs -> WAP to show numbers entered by user except multiples of 10
    int n;
    do{
        cout << "Enter a number : ";
        cin >> n;
        if(n%10 == 0){
            continue;
        }
        cout<<"you entered "<<n<<endl; //Will not work for number which is a multiple of 10
    }while(true);
    return 0;
}
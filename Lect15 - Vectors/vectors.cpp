#include <iostream>
#include <vector>
using namespace std;

int main(){
    // vector<int> vec1(5,1);
    // cout << vec1.size() << "\n";

    // for(int i=0; i<vec1.size(); i++){
    //     cout << vec1[i] << " ";
    // }
    // cout << endl;


    vector <int> vec2 = {1,2,3,4};
    cout << "Size : " << vec2.size() << endl; // 4
    cout << "Capacity : " << vec2.capacity() << endl; // 4

    vec2.push_back(5);
    cout << "Size : " << vec2.size() << endl; // 5
    cout << "Capacity : " << vec2.capacity() << endl; //8
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

void generate(vector<string>& vec,int n,string str, int l, int r){
        if(l == n && r == n){
            vec.push_back(str);
            return;
        }
        if(l > n) return;
        generate(vec,n,str+'(',l++,r);
        if(l!=r) generate(vec,n,str+')',l,r++);
    }
int main(){
    vector<string> vec;
    generate(vec,2,"",0,0);
    for(int i=0; i<vec.size(); i++){
        cout << vec[i] << endl;
    }
}

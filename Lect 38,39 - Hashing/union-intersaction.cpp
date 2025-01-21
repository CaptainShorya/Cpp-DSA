#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

//Union and Intersection

void Union(vector<int> vect1, vector<int> vect2){
    unordered_set<int> s;

    for(int el : vect1){
        s.insert(el);
    }
    for(int el : vect2){
        s.insert(el);
    }
    cout << "Union : " ;
    for(int el : s){
        cout << el << " ";
    }
    cout << endl;
}

void Intersection(vector<int> vect1, vector<int> vect2){
    unordered_set<int> s;

    for(int el : vect1){
        s.insert(el);
    }

    cout << "Intersection : " ;
    for(int i=0; i<vect2.size(); i++){
        if(s.find(vect2[i]) != s.end()){ //FOUND
            cout << vect2[i] << " ";
            s.erase(vect2[i]); //So that no duplicate element gets printed in intersection(Dry Run example)
        }
    }

}

int main(){
    vector<int> vect1 = {7,3,9};
    vector<int> vect2 = {6,3,9,2,9,4};

    Union(vect1,vect2);
    Intersection(vect1,vect2);
    return 0;
}
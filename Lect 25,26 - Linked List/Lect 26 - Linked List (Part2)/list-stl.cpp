#include <iostream>
#include <list>
#include <iterator>
using namespace std;

void printLL(list<int> ll){
    list<int>::iterator itr;

    for(itr = ll.begin(); itr != ll.end(); itr++){
        cout << (*itr) << "->";
    }
    cout << "NULL\n";

}

int main(){
    list<int> ll;

    ll.push_front(2);
    ll.push_front(1);

    ll.push_back(3);
    ll.push_back(4);

    printLL(ll);

    cout << "Size of LL : " << ll.size() << endl;

    cout << "Head = " << ll.front() << endl;
    cout << "Tail = " << ll.back() << endl;

    ll.pop_back();
    printLL(ll);
    
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

//Itenary from Tickets

void printItinerary(unordered_map<string,string> tickets){
    //Starting point
    unordered_set<string> to;

    for(pair<string,string> ticket : tickets){ //<from,to>
        to.insert(ticket.second);
    }

    string start = "";
    for(pair<string,string> ticket : tickets){ 
        if(to.find(ticket.first) == to.end()){ //starting point
            start = ticket.first;
        }
    }

    cout << "Start ->" << " ";
    while(tickets.count(start)){
        cout << tickets[start] << "-> ";
        start = tickets[start];
    }
    cout << "Destination\n";
}

int main(){
    unordered_map<string,string> tickets;
    tickets["Chennai"] = "Bengaluru";
    tickets["Mumbai"] = "Delhi";
    tickets["Goa"] = "Chennai";
    tickets["Delhi"] = "Goa";

    printItinerary(tickets);
    return 0;
}






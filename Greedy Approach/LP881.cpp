//Boats to Save People
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        //Greedy -> Chancees(Lightest + heaviest) >> Chances(Heavier + Heavier) 
        //That's why Adjacent pair matching does not work 
        sort(people.begin(),people.end());
        int boats = 0;
        int i=0; 
        int j=people.size()-1;
        while(i<=j){
            if(people[i]+people[j] <= limit) {
                boats++; //Allocate a boat to pair
                i++;
                j--;
            }else{
                boats++; //Allocated a boat to the heaviest
                j--;
            }
        }
        return boats;
    }
};
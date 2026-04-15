// Keys and Rooms
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> qu;
        unordered_set<int> st;   // stores visited rooms

        st.insert(0);            // start from room 0 (initially unlocked)
        // push all keys from room 0
        for(int num : rooms[0]){
            st.insert(num);      // mark as visited immediately
            qu.push(num);        // process these rooms via BFS
        }
        while(!qu.empty()){
            int key = qu.front();
            qu.pop();
            // explore all rooms accessible from current room
            for(int num : rooms[key]){
                if(!st.count(num)){   // visit only unvisited rooms
                    qu.push(num);     // add to queue for further exploration
                    st.insert(num);   // mark visited (important for BFS)
                }
            } 
        }
        // check if all rooms are visited
        return rooms.size() == st.size();
    }
};
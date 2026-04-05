#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &khatam) {
        // code here
        sort(start.begin(),start.end());
        sort(khatam.begin(), khatam.end());
        int rooms = 0; //Current Active rooms
        int ans = 0; //Tracks maximum rooms used at a time
        int i=0, j=0;
        while(i < start.size()){
            if(start[i] < khatam[j]){ // a meeting is starting
                rooms++;
                ans = max(rooms,ans);
                i++;
            }else if(start[i] > khatam[j]){ // a meeting is ending
                rooms--;
                j++;
            }else{ // one will vacate room and one will occupy
                i++;
                j++;
            }
        }
        return ans;
    }
};

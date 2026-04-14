// LP 455 : Assign Cookies 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int ans = 0;
        int j = s.size()-1;
        for(int i=g.size()-1; i>=0; i--){
            if(j >= 0 && s[j] >= g[i]){
                j--;
                ans++;
            }
        }
        return ans;
    }
};
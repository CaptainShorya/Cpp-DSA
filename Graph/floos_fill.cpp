#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void fillup(vector<vector<int>>& image, int sr, int sc, int color,int val){
        if(image[sr][sc] == color) return; // already visited → don’t go again
        image[sr][sc] = color; // Marking it as visited
        if(sc != 0 && image[sr][sc-1] == val) fillup(image,sr,sc-1,color,val);
        if(sr != image.size()-1 && image[sr+1][sc] == val) fillup(image,sr+1,sc,color,val);
        if(sc != image[0].size()-1 && image[sr][sc+1] == val) fillup(image,sr,sc+1,color,val);
        if(sr != 0 && image[sr-1][sc] == val) fillup(image,sr-1,sc,color,val);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        fillup(image,sr,sc,color,image[sr][sc]);
        return image;
    }
};

//Approach 2 
class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int originalColor){
        if(sr < 0 || sc < 0 || sr == image.size() || sc == image[0].size()) return;
        if(image[sr][sc] != originalColor) return; // If adjacent element not same as of originalColor ,return back(No change required)

        if(image[sr][sc] == color) return; //Avoids Infinite Recursion possiblity
        image[sr][sc] = color;
        dfs(image,sr-1,sc,color,originalColor);
        dfs(image,sr,sc-1,color,originalColor);
        dfs(image,sr+1,sc,color,originalColor);
        dfs(image,sr,sc+1,color,originalColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image,sr,sc,color,image[sr][sc]);
        return image;
    }
};
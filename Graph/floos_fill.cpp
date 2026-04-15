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
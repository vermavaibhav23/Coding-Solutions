//Flood Fill
//Compiler - C++
//https://leetcode.com/problems/flood-fill/description/

class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr,int sc, int color, int ogcolor, int m, int n) {
        image[sr][sc] = color;

        if(sr>0 && image[sr-1][sc] == ogcolor) {
            dfs(image,sr-1,sc,color,ogcolor,m,n); //up
        } 

        if(sr<m-1 && image[sr+1][sc] == ogcolor) {
            dfs(image,sr+1,sc,color,ogcolor,m,n);  //down
        } 

        if(sc>0 && image[sr][sc-1] == ogcolor) {
            dfs(image,sr,sc-1,color,ogcolor,m,n);  //left
        }

        if(sc<n-1 && image[sr][sc+1] == ogcolor) {
            dfs(image,sr,sc+1,color,ogcolor,m,n);  //right
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int ogcolor = image[sr][sc];
        if (ogcolor == color){
            return image;
        }   
        dfs(image,sr,sc,color,ogcolor,m,n);
        return image;
    }
};
//https://leetcode.com/problems/triangle/
//Compiler - C++
//Triangle

class Solution {
public:
    void helper(vector<vector<int>>& triangle, int size) {
        for(int i = 1; i < size; i++) {
            vector<int>temp = triangle[i-1];
            int tempsize = temp.size();
            for(int j = 0; j < triangle[i].size(); j++) {
                int a = INT_MAX;
                int b = INT_MAX;
                if(j != tempsize) {
                    b = triangle[i][j] + triangle[i-1][j];
                }
                if(j > 0) {
                    a = triangle[i][j] + triangle[i-1][j-1];
                } 
                triangle[i][j] = min(a,b);
            }
        }
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() <= 0) {
            return 0;
        }
        if(triangle.size() == 1) {
            return triangle[0][0];
        }
        int size = triangle.size();
        helper(triangle, size);
        int min = INT_MAX;
        for(int i = 0; i < triangle[size-1].size(); i++) {
            if(triangle[size-1][i] < min) {
                min = triangle[size-1][i];
            }
        }
        return min;
    }
};
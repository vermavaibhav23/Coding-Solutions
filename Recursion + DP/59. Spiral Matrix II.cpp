//59. Spiral Matrix II
//C++
//https://leetcode.com/problems/spiral-matrix-ii/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int num = 1;
        
        int top = 0;
        int down = n-1;
        int left = 0;
        int right = n-1;

        while(left <= right && top <= down) {
            for(int i = left; i <= right; i++) {
                res[top][i] = num;
                num++;
            }
            top++;
            for(int i = top; i <= down; i++) {
                res[i][right] = num;
                num++;
            }
            right--;
            for(int i = right; i >= left; i--) {
                res[down][i] = num;
                num++;
            }
            down--;
            for(int i = down; i >= top; i--) {
                res[i][left] = num;
                num++;
            }
            left++;
        }

        return res;
    }
};
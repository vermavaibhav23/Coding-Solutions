//Surrounded Regions
//Compiler - C++
//https://leetcode.com/problems/surrounded-regions/description/


class Solution {
public:
    void replace(vector<vector<char>>& board, char toreplace, char replacewith, int xsize, int ysize) {
        for(int i=0; i<ysize; i++) {
            for(int j=0; j<xsize; j++) {
                if(board[i][j] == toreplace) {
                    board[i][j] = replacewith;
                }
            }
        }
        return;
    }
    void dfs(vector<vector<char>>& board, int xsize, int ysize, int i, int j){
        board[i][j] = 'A';

        if(i>0 && board[i-1][j] == 'O') {        //up
            dfs(board, xsize, ysize, i-1, j);
        }
        if(j>0 && board[i][j-1] == 'O') {        //left
            dfs(board, xsize, ysize, i, j-1);
        }
        if(j<(xsize-1) && board[i][j+1] == 'O') {        //right
            dfs(board, xsize, ysize, i, j+1);
        }
        if(i<(ysize-1) && board[i+1][j] == 'O') {        //down
            dfs(board, xsize, ysize, i+1, j);
        }
    }
    void solve(vector<vector<char>>& board) {
        int xsize = board[0].size();
        int ysize = board.size();
        for(int i=0; i<xsize; i++) {               //1st row
            if(board[0][i] == 'O') {
                dfs(board, xsize, ysize, 0, i);
            }
        }
        for(int i=0; i<ysize; i++) {               //1st col
            if(board[i][0] == 'O') {
                dfs(board, xsize, ysize, i, 0);
            }
        }
        for(int i=0; i<ysize; i++) {               //last col
            if(board[i][xsize-1] == 'O') {
                dfs(board, xsize, ysize, i, xsize-1);
            }
        }
        for(int i=0; i<xsize; i++) {               //last row
            if(board[ysize-1][i] == 'O') {
                dfs(board, xsize, ysize, ysize-1, i);
            }
        }

        //replace all O with X, then all A with O
        replace(board, 'O', 'X', xsize, ysize);
        replace(board, 'A', 'O', xsize, ysize);

        return;
    }
};
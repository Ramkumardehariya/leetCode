class Solution {
public:
    bool isSafe(vector<string> &board, int n, int col, int row){
        int x = row;
        int y = col;
        
        while(y >= 0 && x >= 0){
            if(board[x][y] == 'Q'){
                return false;
            }
            x--;
            y--;
        }

        x = row;
        y = col;
        while(y >= 0){
            if(board[x][y] == 'Q'){
                return false;
            }
            y--;
        }
        x = row;
        y = col;
        while(x < n && y >= 0){
            if(board[x][y] == 'Q'){
                return false;
            }
            x++;
            y--;
        }
        return true;
    }
    void solve(vector<string>&board, vector<vector<string>> &ans, int n, int col){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row = 0; row<n; row++){
            if(isSafe(board, n, col, row)){
                board[row][col] = 'Q';
                solve(board, ans, n, col+1);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        vector<vector<string>> ans;

        for(int i = 0; i<n; i++){
            for(int j = 0;j<n;j++){
                board[i].push_back('.');
            }
        }

        solve(board, ans, n, 0);
        return ans;
    }
};
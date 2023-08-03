class Solution {
public:

    void solve(int i, int j,vector<vector<char>>& board, vector<vector<bool>>& vis){
        if(i < 0 || j< 0 || i>=board.size() || j >=board[0].size()){
            return;
        }

        if(board[i][j] == 'X' && !vis[i][j]){
            vis[i][j] = 1;
            solve(i+1, j, board, vis);
            solve(i-1, j, board, vis);
            solve(i, j+1, board, vis);
            solve(i, j-1, board, vis);
        }
        
    }
    int countBattleships(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> vis(n, vector<bool> (m, 0));
        int ans = 0;


        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j] && board[i][j] == 'X'){
                    ans++;
                    solve(i, j, board, vis);
                }
                vis[i][j] = 1;
            }
        }
        return ans;
    }
};
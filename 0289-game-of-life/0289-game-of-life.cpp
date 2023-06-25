class Solution {
public:

    int check(int r, int c, int n, int m, vector<vector<int>>& board, int dxdy[][2]){
        int count = 0;

        for(int i = 0; i<8; i++){
            int row = r+dxdy[i][0];
            int col = c+dxdy[i][1];

            if(row>=0 && col>=0 && row<n && col<m && board[row][col] == 1){
                count++;
            }
        }
        return count;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> visited = board;
        int dxdy[8][2] = {{1,0},{0,1},{1,1},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                int count = check(i, j, n, m, board, dxdy);
                if(count < 2){
                    visited[i][j] = 0;
                }
                else if((count == 2 || count == 3) && board[i][j] == 1){
                    visited[i][j] = 1;
                }
                else if(count>3 && board[i][j] == 1){
                    visited[i][j] = 0 ;
                }
                else if(count == 3 && board[i][j] == 0){
                    visited[i][j] = 1;
                }

            }
        }
        board = visited;
    }
};
class Solution {
public:
    int adj(vector<vector<char>>& board, int x, int y){
        int count = 0;
        for(int i = max(0, x-1); i<x+2 && i<board.size(); i++){
            for(int j = max(0, y-1); j<y+2 && j<board[0].size(); j++){
                if(board[i][j] == 'M'){
                    count++;
                }
            }
        }
        return count;
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int> click) {
        int x = click[0];
        int y = click[1];

        if(board[x][y] == 'B' || board[x][y] < '9'){
            return board;
        }
        if(board[x][y] == 'M'){
            board[x][y] = 'X';
            return board;
        }

        int count = adj(board, x, y);
        if(count){
            board[x][y] = count+'0';
        }
        else{
            board[x][y] = 'B';
            for(int i = max(0,x-1); i<x+2 && i<board.size(); i++){
                for(int j = max(0, y-1); j<y+2 && j<board[0].size(); j++){
                    if(i == x && j == y){
                        continue;
                    }
                    updateBoard(board, {i, j});
                }
            }
        }
        
        return board;
    }
};
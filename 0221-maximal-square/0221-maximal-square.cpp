class Solution {
public:

    int solve(int i, int j, vector<vector<char>> &matrix, int &maxi, vector<vector<int>> &dp){
        if(i >= matrix.size() || j>= matrix[0].size()){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int bottom = solve(i+1, j, matrix, maxi, dp);
        int diagonal = solve(i+1, j+1, matrix, maxi, dp);
        int right = solve(i, j+1, matrix, maxi, dp);


        if(matrix[i][j] == '1'){
             int side = min(bottom , min(diagonal, right))+1;
             maxi = max(maxi, side);
             return dp[i][j] = side;
        }
        else{
            return dp[i][j] = 0;
        }
    }


    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        solve(0, 0, matrix, maxi, dp);


        return maxi*maxi;
    }
};
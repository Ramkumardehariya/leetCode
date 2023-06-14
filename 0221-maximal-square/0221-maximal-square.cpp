class Solution {
public:

    int solve(vector<vector<char>>& matrix, int i, int j, int &maxi){
        if(i>=matrix.size() || j >= matrix[0].size()){
            return 0;
        }

        int num = 0;
        int right = solve(matrix, i, j+1, maxi);
        int diagonal = solve(matrix, i+1, j+1, maxi);
        int down = solve(matrix, i+1, j, maxi);

        if(matrix[i][j] == '1'){
            int ans = 1 + min(right, min(diagonal, down));
            maxi = max(maxi, ans);
            return ans;
        }
        else{
            return 0;
        }
    }

    int solveMem(vector<vector<char>>& matrix, int i, int j, int &maxi, vector<vector<int>>&dp){
        if(i >= matrix.size() || j >= matrix[0].size()){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int right = solveMem(matrix, i, j+1, maxi, dp);
        int diagonal = solveMem(matrix, i+1, j+1, maxi, dp);
        int down = solveMem(matrix, i+1, j, maxi, dp);

        if(matrix[i][j] == '1'){
            dp[i][j] = 1 + min(right, min(diagonal, down));
            maxi = max(maxi, dp[i][j]);

            return dp[i][j];

        }
        else{
            return dp[i][j] = 0;
        }
    }

    int solveTab(vector<vector<char>>& matrix, int &maxi){

        int row = matrix.size();
        int col = matrix[0].size();

        vector<vector<int>> dp(row+1, vector<int>(col+1, 0));

        for(int i = row-1; i>=0; i--){
            for(int j = col-1; j>=0; j--){
                int right = dp[i][j+1];
                int diagonal = dp[i+1][j+1];
                int down = dp[i+1][j];

                if(matrix[i][j] == '1'){
                    dp[i][j] = 1 + min(right, min(diagonal, down));
                    maxi = max(dp[i][j],maxi);
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        return dp[0][0];
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;
        //recursion
        // solve(matrix, 0, 0, maxi);

        //memoization
        // int n = matrix.size();
        // int m = matrix[0].size();
        // vector<vector<int> >dp(n,vector<int> (m,-1));
        // solveMem(matrix,0,0,maxi,dp);


        //solve tabulization method
        solveTab(matrix,maxi);
        return maxi*maxi;
    }
};
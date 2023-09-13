class Solution {
public:
    int mod = 1000000007;

    long solve(int m, int n, int max, int i, int j, vector<vector<vector<int>>> &dp){
        if(i < 0 || j < 0 || i >= m || j >= n){
            return 1;
        }
        if(max <= 0){
            return 0;
        }

        if(dp[i][j][max] != -1){
            return dp[i][j][max];
        }
        long res = 0;

        res += solve(m, n, max-1, i+1, j, dp);
        res += solve(m, n, max-1, i, j+1, dp);
        res += solve(m, n, max-1, i-1, j, dp);
        res += solve(m, n, max-1, i, j-1, dp);

        return dp[i][j][max] = res%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>> (n+1, vector<int> (maxMove+1, -1)));

        return solve(m, n, maxMove, startRow, startColumn, dp)%mod;
    }
};
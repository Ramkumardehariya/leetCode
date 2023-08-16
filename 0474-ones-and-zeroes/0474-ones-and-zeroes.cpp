class Solution {
public:

    int solve(vector<string> &strs, int i, int m, int n, vector<vector<vector<int>>> &dp){
        if(i >= strs.size() || m < 0 || n < 0){
            return 0;
        }

        if(dp[m][n][i] != -1){
            return dp[m][n][i];
        }
        int zeros = count(strs[i].begin(), strs[i].end(), '0');
        int ones = count(strs[i].begin(), strs[i].end(), '1');

        if(m-zeros >= 0 && n-ones >= 0){
            return dp[m][n][i] = max(1+solve(strs, i+1, m-zeros, n-ones, dp), solve(strs, i+1, m, n, dp));
        }
        else{
            return dp[m][n][i] = solve(strs, i+1, m, n, dp);
        }
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();

        vector<vector<vector<int>>> dp(m+1, vector<vector<int>> (n+1, vector<int> (size+1, -1)));

        return solve(strs, 0, m, n, dp);
    }
};
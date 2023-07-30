class Solution {
public:
    int solve(string s, int i, int j, vector<vector<int>> &dp){
        if(i > j){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int x = i;
        while(s[x] == s[x+1] && x+1<j){
            x++;
        }

        int ans = 1 + solve(s, x+1, j, dp);

        for(int k = x+1; k<=j; k++){
            if(s[k]  == s[i]){
                ans = min(ans, solve(s, x+1, k-1, dp) + solve(s, k, j, dp));
            }
        }

        return dp[i][j] = ans;
    }
    int strangePrinter(string s) {
        vector<vector<int>> dp(s.size(), vector<int> (s.size(), -1));

        return solve(s, 0, s.size()-1, dp);
    }
};
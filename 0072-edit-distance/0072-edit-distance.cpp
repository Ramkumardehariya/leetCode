class Solution {
public:
    int solve(string &a, string &b, int i, int j, vector<vector<int>> &dp){
        if(i == a.size()){
            return b.size()-j;
        }
        if(j == b.size()){
            return a.size()-i;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = 0;
        if(a[i] == b[j]){
            ans = solve(a, b, i+1, j+1, dp);
        }
        else{
            int insert = solve(a, b, i, j+1, dp);
            int replace = solve(a, b, i+1, j+1, dp);
            int deletea = solve(a,b, i+1, j, dp);

            ans = 1+ min(insert, min(replace, deletea));
        }

        return dp[i][j] = ans;
    }

    int solveTab(string &a, string &b){
        vector<vector<int>> dp(a.size()+1, vector<int>(b.size()+1, 0));

        for(int j = 0; j<b.size(); j++){
            dp[a.size()][j] = b.size()-j;
        }
        for(int i = 0; i<a.size(); i++){
            dp[i][b.size()] = a.size()-i;
        }

        for(int i = a.size()-1; i>=0; i--){
            for(int j = b.size()-1; j>=0; j--){
                int ans = 0;
                if(a[i] == b[j]){
                    ans = dp[i+1][j+1];
                }
                else{
                    ans = 1+min(dp[i][j+1], min(dp[i+1][j+1], dp[i+1][j]));
                }
                dp[i][j] = ans;
            }
        }

        return dp[0][0];
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
        //return solve(word1, word2, 0, 0, dp);

        return solveTab(word1, word2);
    }
};
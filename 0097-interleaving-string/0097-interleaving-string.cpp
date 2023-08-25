class Solution {
public:

    bool solve(string s1, string s2, string s3, int i, int j, int k, vector<vector<int>> &dp){
        if(i == s1.length() && j == s2.length() && k == s3.length()){
            return true;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        bool s1check = false;
       
        if(s1[i] == s3[k] && i != s1.length()){
            s1check = solve(s1, s2, s3, i+1, j, k+1, dp);
        }
        
        bool s2check = false;
       
        if(s2[j] == s3[k] && j != s2.length()){
            s2check = solve(s1, s2, s3, i, j+1, k+1, dp);
        }
        
        dp[i][j] = s1check || s2check;
        return dp[i][j];
    }
    bool isInterleave(string s1, string s2, string s3) {

        int a = s1.size();
        int b= s2.size();

        vector<vector<int>> dp(a+1, vector<int> (b+1, -1));
        return solve(s1, s2, s3, 0, 0, 0, dp);
    }
};
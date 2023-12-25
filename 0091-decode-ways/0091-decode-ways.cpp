class Solution {
public:

    int solve(string s, int i, vector<int> &dp){
        if(i == s.size()){
            return 1;
        }

        if(s[i] == '0'){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        int one = solve(s, i+1, dp);

        int two = 0;

        if((i < s.size()-1) && ((s[i] == '2' && s[i+1] <= '6') || s[i] == '1' && s[i+1] <= '9' )){
            two = solve(s, i+2, dp);
        }
        return dp[i] = one + two;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size()+1, -1);

        return solve(s, 0, dp);
    }
};
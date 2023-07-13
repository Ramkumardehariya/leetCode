class Solution {
public:
    int solve(int n,int total, vector<int> &dp){
        if(n<=1){
            return 1;
        }

        int notTake = solve(n-1, total, dp);
        int take = 0;
        if(total >= n){
            take = n*solve(n, total-n, dp);
        }

        return dp[n] = max(take, notTake);
    }
    int integerBreak(int n) {
        if(n<4){
            return n-1;
        }
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 1;
        return solve(n-1,n, dp);
    }
};
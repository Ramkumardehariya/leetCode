class Solution {
public:
    int solve(int n){
        if(n <= 1){
            return n;
        }

        return solve(n-1)+solve(n-2);
    }
    
    int solveMem(int n, vector<int> &dp){
        if(n <= 1){
            return n;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        return dp[n] = solveMem(n-1,dp)+solveMem(n-2, dp);
    }
    
    int fib(int n) {
        //int ans = solve(n);
        vector<int> dp(n+1, -1);
        int ans = solveMem(n, dp);
        return ans;
    }
};
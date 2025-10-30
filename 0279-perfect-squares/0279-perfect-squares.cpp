class Solution {
public:
    int solve(int n, vector<int> &dp){
        if(n == 0){
            return 0;
        }
        if(n < 0){
            return INT_MAX;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        int ans = INT_MAX;
        for(int i = 1; i<=n; i++){
            int check = solve(n-pow(i,2), dp);
            if(check != INT_MAX){
                ans = min(ans, 1+check);
            }
        }
        return dp[n] = ans;
    }

    int solveTab(int n){
        vector<int> dp(n+1, INT_MAX);

        dp[0] = 0;

        for(int m = 1; m<=n; m++){
            int ans = INT_MAX;
            for(int i = 1; i<=n; i++){
                if(m-pow(i,2) >= 0){
                    int check = dp[m-pow(i,2)];
                    if(check != INT_MAX){
                        ans = min(ans, 1+check);
                    }
                }
            }
            dp[m] = ans;
        }
        return dp[n];
    }
    int numSquares(int n) {
        // vector<int> dp(n+1, -1);
        // return solve(n, dp);
        return solveTab(n);
    }
};
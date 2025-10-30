class Solution {
public:
    int solve(vector<int> &coins, int amount, vector<int> &dp){
        if(amount < 0){
            return INT_MAX;
        }
        if(amount == 0){
            return 0;
        }
        if(dp[amount] != -1){
            return dp[amount];
        }
        int mini = INT_MAX;
        for(int i = 0; i<coins.size(); i++){
            int ans = solve(coins, amount-coins[i], dp);
            if(ans != INT_MAX){
                mini = min(mini, 1+ans);
            }
        }
    
        return dp[amount] = mini;
    }
   
    int solveTab(vector<int> &coins, int &amount){
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;

        for(int j = 1; j<=amount; j++){
            int mini = INT_MAX;
            for(int i = 0; i<coins.size(); i++){
                if(j-coins[i] >= 0){
                    int ans = dp[j-coins[i]];
                    if(ans != INT_MAX){
                        mini = min(mini, 1+ans);
                    }
                }
            }
            dp[j] = mini;
        }
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        // vector<int> dp(amount+1, -1);
        // int ans = solve(coins, amount, dp);
        int ans = solveTab(coins, amount);
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};
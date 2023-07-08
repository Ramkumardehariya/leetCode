class Solution {
public:
    int solve(int i, vector<int>& coins, int amount){
        if(i == 0){
            if(amount%coins[0] == 0){
                return amount/coins[0];
            }
            return -1;
        }

        int notTake = 0 + solve(i-1, coins, amount);

        int take = INT_MAX;
        if(coins[i] <= amount){
            take = 1+solve(i, coins, amount-coins[i]);
        }

        return min(take,notTake);
    }

    int solveMem(int i, vector<int>& coins, int amount, vector<vector<int>> &dp){
        if(i == 0){
            if(amount%coins[0] == 0){
                return amount/coins[0];
            }
            return 1e9;
        }

        if(dp[i][amount] != -1){
            return dp[i][amount];
        }

        int notTake = 0 + solveMem(i-1, coins, amount, dp);

        int take = INT_MAX;
        if(coins[i] <= amount){
            take = 1+solveMem(i, coins, amount-coins[i], dp);
        }

        return dp[i][amount] = min(take,notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // return solve(coins.size()-1, coins, amount);

        //Memoization
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));

        int ans = solveMem(n-1, coins, amount, dp);
        if(ans >= 1e9){
            return -1;
        }
        return ans;
    }
};
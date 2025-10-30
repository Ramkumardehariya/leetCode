class Solution {
public:
    int solve(vector<int> &coins, int amount){
        if(amount < 0){
            return INT_MAX;
        }
        if(amount == 0){
            return 0;
        }

        int mini = INT_MAX;
        for(int i = 0; i<coins.size(); i++){
            int ans = solve(coins, amount-coins[i]);
            if(ans != INT_MAX){
                mini = min(mini, 1+ans);
            }
        }
    
        return mini;
    }
   
    int coinChange(vector<int>& coins, int amount) {
        int ans = solve(coins, amount);
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};
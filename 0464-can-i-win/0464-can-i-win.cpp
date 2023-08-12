class Solution {
public:

    bool solve(int max, int total, int k, vector<int> &dp){
        if(total <= 0){
            return 0;
        }

        if(dp[k] != -1){
            return dp[k];
        }

        for(int i  = 0; i<max; i++){
            if(!(k&(1<<i)) && !solve(max, total-(i+1), k|1<<i, dp)){
                return dp[k] = 1;
            }
        }
        return dp[k] = 0;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(desiredTotal == 0){
            return true;
        }
        int total = maxChoosableInteger * (maxChoosableInteger+1)/2;
        if(total < desiredTotal){
            return false;
        }
        if(total == desiredTotal){
            return maxChoosableInteger%2;
        }

        vector<int> dp(1<<20, -1);

        return solve(maxChoosableInteger, desiredTotal, 0, dp);
    }
};
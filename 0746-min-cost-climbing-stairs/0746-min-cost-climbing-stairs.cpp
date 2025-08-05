class Solution {
public:

    int solve(vector<int> &cost, int n){
        
        vector<int> dp(n+1);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 2; i<=n; i++){
            dp[i] = cost[i]+min(dp[i-1], dp[i-2]);
        }
        // if(n == 0){
        //     return cost[0];
        // }
        // if(n == 1){
        //     return cost[1];
        // }

        // return min(solve(cost, n-1), solve(cost, n-2))+cost[n];
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n < 3){
            return min(cost[0],cost[1]);
        }
        return min(solve(cost, n-1), solve(cost,n-2));
    }
};
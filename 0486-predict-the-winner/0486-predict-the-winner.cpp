class Solution {
public:

    int solve(vector<int> &nums, int i, int j, int chance, vector<vector<vector<int>>> &dp){
        if(i > j){
            return 0;
        }
        
        if(dp[i][j][chance] != -1){
            return dp[i][j][chance];
        }

        if(chance == 0){
            return dp[i][j][chance] = max(nums[i] + solve(nums, i+1, j, 1, dp) , nums[j] + solve(nums, i, j-1, 1, dp));
        }
        else{
            return dp[i][j][chance] = min(solve(nums, i+1, j, 0, dp), solve(nums, i, j-1, 0, dp));
        }
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        long long two = 0;

        for(int i= 0; i<n; i++){
            two += nums[i];
        }

        vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int> (2, -1)));
        long long one = solve(nums, 0, n-1, 0, dp);
        two -= one;
        return one >= two;
    }
};
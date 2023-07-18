class Solution {
public:
    int solveMem(vector<int>& nums, int target, vector<int> &dp){
        if(target == 0){
            return 1;
        }
        if(target < 0 ){
            return 0;
        }
        if(dp[target] != -1){
            return dp[target];
        }
        
        int ans = 0;
        for(int i = 0; i<nums.size(); i++){
            ans += solveMem(nums,target-nums[i], dp);
        }

        return dp[target] = ans;
    }

    int Tabulation(vector<int> &nums, int target){
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        int n = nums.size();
        for(int j = 1; j <= target; j++){
            long long int ans = 0;
            for(int i = 0; i<n; i++){
                if(j >= nums[i]){
                    ans += dp[j-nums[i]];
                }
            }
            dp[j] = ans;
        }
        return dp[target];
    }

    int combinationSum4(vector<int>& nums, int target) {

        //recursion
        // return solve(nums, target);

        //memoization
        // vector<int> dp(target+1, -1);
        // return solveMem(nums, target, dp);

        //Tabulation
        return Tabulation(nums, target);
    }
};
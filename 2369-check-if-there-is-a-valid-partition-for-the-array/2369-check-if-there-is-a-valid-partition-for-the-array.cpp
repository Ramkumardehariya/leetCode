class Solution {
public:

    bool solve(vector<int> &nums,int n, int i, vector<int> &dp){
        if(i == n){
            return true;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        bool res = false;
        if(i+1 < n && nums[i] == nums[i+1]){
            res = solve(nums,n, i+2, dp);

            if(i+2 < n && nums[i+1] == nums[i+2]){
                res = res || solve(nums, n, i+3, dp);
            }
        }

        if(i+2 < n && nums[i]+1 == nums[i+1] && nums[i+1]+1 == nums[i+2]){
            res = solve(nums, n, i+3, dp);
        }

        return dp[i] = res;
    }
    bool validPartition(vector<int>& nums) {
        int n = nums.size();

        if(n == 2){
            return nums[0] == nums[1];
        }

        vector<int> dp(n, -1);
        return solve(nums,n, 0, dp);
    }
};
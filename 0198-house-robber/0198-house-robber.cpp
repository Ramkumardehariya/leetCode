class Solution {
public:

    int solveMem(vector<int> &nums, int i, vector<int> &dp){
        if(i >= nums.size()){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        int incl = nums[i] + solveMem(nums, i+2,dp);
        int excl =  solveMem(nums, i+1,dp);

        int maxi = INT_MIN;
        maxi = max(incl, excl);

        return dp[i] = maxi;
    }
    
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }

        vector<int> dp(nums.size()+1,-1);
        return solveMem(nums, 0, dp);
    }
};
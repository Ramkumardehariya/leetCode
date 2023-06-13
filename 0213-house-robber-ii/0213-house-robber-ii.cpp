class Solution {
public:

    int solve1(vector<int> &nums, int n, vector<int> &dp){
        if(n == 1){
            return nums[1];
        }
        if(n<=0){
            return 0;
        }

        if(dp[n] != -1){
            return dp[n];
        }
        
        int incl = nums[n] + solve1(nums, n-2, dp);
        int excl = solve1(nums, n-1, dp);

        dp[n] = max(incl,excl);

        return dp[n];
    }

    int solve2(vector<int> &nums, int i, vector<int> &dp){
        if(i == nums.size()-2){
            return nums[i];
        }
        if(i>=nums.size()-1){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }
        
        int incl = nums[i] + solve2(nums,i+2, dp);
        int excl = solve2(nums,i+1, dp);

        dp[i] = max(incl, excl);
        
        return dp[i];
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        int n = nums.size();

        vector<int> dp1(n+1, -1);
        vector<int> dp2(n+1, -1);

        int ans1 = solve1(nums, n-1, dp1);
        int ans2 = solve2(nums, 0, dp2);

         
        return max(ans1, ans2);;
    }
};
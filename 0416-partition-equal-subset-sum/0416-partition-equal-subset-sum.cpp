class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();

        for(int i = 0; i<n; i++){
            sum += nums[i];
        }

        if(sum % 2 != 0){
            return false;
        }

        int tar = sum/2;

        vector<vector<int>> dp(n+1, vector<int> (tar+1, 0));

        for(int i = 1; i<n+1; i++){
            dp[i][0] = 1;
        }

        for(int i = 1; i<n+1; i++){
            for(int j = 1; j<tar+1; j++){
                bool take = 0;
                if(j >= nums[i-1]){
                    take =  dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
                bool notTake = dp[i-1][j];

                dp[i][j] = take || notTake;
            }
        }

        return dp[n][tar];
    }
};
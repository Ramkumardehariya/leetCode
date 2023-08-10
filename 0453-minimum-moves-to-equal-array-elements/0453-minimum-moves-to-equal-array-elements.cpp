class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini = INT_MAX;
        int n = nums.size();
        if(n == 1){
            return 0;
        }

        for(int i = 0; i<n; i++){
            mini = min(mini, nums[i]);
        }
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += nums[i];
        }

        return sum-nums.size()*mini;
    }
};
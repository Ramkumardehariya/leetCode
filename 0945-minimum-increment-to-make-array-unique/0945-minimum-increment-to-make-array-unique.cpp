class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int ans = 0;
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 1; i<n; ++i){
            if(nums[i] <= nums[i-1]){
                int diff = nums[i-1]+1-nums[i];
                ans += diff;
                nums[i] += diff;
            }   
        }
        return ans;
    }
};
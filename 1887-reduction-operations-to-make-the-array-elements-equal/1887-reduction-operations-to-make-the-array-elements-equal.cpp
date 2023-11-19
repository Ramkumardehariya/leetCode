class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int prev = nums[0];
        int n = nums.size();
        int ans = 0;

        for(int i = 1; i<nums.size(); i++){
            if(prev != nums[i]){
                ans += n-i;
                prev = nums[i];
            }
        }

        return ans;
    }
};
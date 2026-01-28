class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int ans = 0;
        for(auto num: nums){
            ans += num;
        }
        int sum = 0;
        for(int i = 0; i<nums.size(); i++){
            ans -= nums[i];
            if(sum == ans){
                return i;
            }
            sum += nums[i];
        }
        return -1;
    }
};
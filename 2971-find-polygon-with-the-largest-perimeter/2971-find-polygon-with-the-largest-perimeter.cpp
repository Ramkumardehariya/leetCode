class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long prevSum = 0;
        long long ans = -1;

        for(int i = 0; i<nums.size(); i++){
            if(i >= 2 && nums[i] < prevSum){
                ans = nums[i] + prevSum;
            }
            prevSum += nums[i];
        }
        return ans;
    }
};
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum = accumulate(nums.begin(),nums.end(),0);

        int maxLength = -1;
        int sum = 0;
        
        for(int l = 0, r = 0; r<nums.size(); r++){
            sum += nums[r];

            while(sum > totalSum-x && l <= r){
                sum -= nums[l++];
            }
            if(sum == totalSum-x){
                maxLength = max(maxLength, r-l+1);
            }
        }
        return maxLength == -1 ? -1 : nums.size() - maxLength;
    }
};
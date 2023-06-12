class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int mini = n+1;
        int window = 0;
        int left = 0;
        
        for(int right = 0; right<nums.size(); right++){

            window = window+nums[right];

            while(window >= target){
                mini = min(mini, right-left+1);
                window = window - nums[left++];
            }
        }
        
        if(mini == n+1){
            return 0;
        }
        return mini;
    }
};
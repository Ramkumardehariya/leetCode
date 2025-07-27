class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int valley = 0;
        int hill = 0;

        for(int i = 1; i<nums.size()-1; i++){
            int left = i-1;
            int right = i+1;
            if(nums[i] == nums[i-1]){
                continue;
            }

            while(left > 0 && nums[left] == nums[i]){
                left--;
            }
            while(right < nums.size() && nums[right] == nums[i]){
                right++;
            }

            if(nums[left] < nums[i] && nums[i] > nums[right]){
                hill++;
            }
            if(nums[left] > nums[i] && nums[i] < nums[right]){
                valley++;
            }
        }
        return valley+hill;
    }
};
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int> temp;
        int count = nums.size()-1;
        while(count != 0){
            for(int i = 0; i<nums.size()-1; i++){
                int sum = nums[i]+nums[i+1];
                nums[i] = sum%10;
            }
            count--;
        }

        return nums[0];
    }
};
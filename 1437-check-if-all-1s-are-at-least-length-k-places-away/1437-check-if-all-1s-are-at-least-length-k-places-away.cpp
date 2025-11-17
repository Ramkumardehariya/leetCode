class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int count = 0;
        int i = 0;
        while(nums[i] != 1){
            i++;
        }
        i++;
        for(; i<nums.size(); i++){
            if(nums[i] == 1){
                if(count >= k){
                    count = 0;
                }
                else{
                    return false;
                }
            }
            else if(nums[i] == 0){
                count++;
            }
        }
        return true;
    }
};
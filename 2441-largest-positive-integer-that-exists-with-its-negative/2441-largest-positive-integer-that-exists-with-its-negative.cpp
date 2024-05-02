class Solution {
public:
    int findMaxK(vector<int>& nums) {
        
        vector<int> temp;

        for(int i = 0; i<nums.size(); i++){
            for(int j = i+1; j<nums.size(); j++){
                if(nums[i] < 0 && nums[j] > 0 && -nums[i] == nums[j]){
                    temp.push_back(nums[j]);
                }
                else if(nums[i] > 0 && nums[j] < 0 && nums[i] == -nums[j]){
                    temp.push_back(nums[i]);
                }
                else{
                    continue;
                }
            }
        }
        int ans = -1;
        for(int i = 0; i<temp.size(); i++){
            ans = max(ans, temp[i]);
        }
        return ans;
    }
};
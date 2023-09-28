class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();

        for(int i = 0; i<n; i++){
            if(nums[i] % 2 == 0){
                ans.insert(ans.begin() + 0,nums[i]);
            }
            else{
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};
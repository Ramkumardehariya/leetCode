class Solution {
public:
    void solve(int i, vector<int>&nums,int &ans, int xorAns){
        if(i == nums.size()){
            ans += xorAns;
            return;
        }

        xorAns =xorAns^nums[i];
        solve(i+1, nums, ans, xorAns);
        xorAns = xorAns^nums[i];
        solve(i+1, nums, ans, xorAns);
    }
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        solve(0, nums, ans, 0);
        return ans;
    }
};
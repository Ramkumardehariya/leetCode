class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> st;
        int maxi = INT_MIN;

        for(int i = 0; i<nums.size(); i++){
            maxi = max(maxi, nums[i]);
            if(nums[i] < 0){
                continue;
            }
            st.insert(nums[i]);
        }

        if(st.size() == 0){
            return maxi;
        }

        vector<int> temp(st.begin(), st.end());

        int ans = 0;

        for(auto it: temp){
            ans += it;
        }

        return ans;
    }
};
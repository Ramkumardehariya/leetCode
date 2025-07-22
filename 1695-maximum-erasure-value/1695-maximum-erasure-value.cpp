class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0;
        int sum = 0;
        set<int> st;

        int j = 0;
        int i = 0;
        int n = nums.size();

        while(j< n){
            sum += nums[j];
            while(st.count(nums[j])){
                st.erase(nums[i]);
                sum -= nums[i];
                i++;
            }
            st.insert(nums[j]);
            ans = max(ans, sum);
            j++;
        }
        return ans;
    }
};
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        map<int,int> mp;
        mp[0] = 1;
        int preSum = 0;

        for(int i = 0; i<n; i++){
            preSum += nums[i];

            int remove = preSum-k;

            ans += mp[remove];

            mp[preSum] += 1;

        }
        return ans;
    }
};
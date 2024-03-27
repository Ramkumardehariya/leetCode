class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long long ans = 0;

        vector<vector<int>> temp;
        int n = nums.size();

        for(int i = 0;  i<n; i++){
            long long sum = 1;
            for(int j = i; j<n; j++){
                sum *= nums[j];
                if(sum >= k){
                    break;
                }
                if(sum < k){
                    ans++;
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int ans = INT_MIN;
        int sum = 0;
        int temp = 0;
        int n = nums.size();

        for(int i= 0; i<n; i++){
            sum += nums[i];
            temp += (nums[i]*i);
        }

        ans = max(ans, temp);

        for(int i = n-1; i>0; i--){
            temp += (sum-nums[i]*n);
            ans = max(ans, temp);
        }

        return ans;
    }
};
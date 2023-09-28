class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        sort(nums.rbegin(), nums.rend());

        for(int i = 0; i<n; i++){
            int j = i+1;
            int k = n-1;

            while(j < k){
                if(nums[j] + nums[k] > nums[i]){
                    ans += k-j;
                    j++;
                }
                else{
                    k--;
                }
            }
        }

        return ans;
    }
};
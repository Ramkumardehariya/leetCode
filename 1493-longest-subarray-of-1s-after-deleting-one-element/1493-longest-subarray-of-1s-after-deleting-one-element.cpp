class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        int c0 = 0;
        int maxi = 0;

        while(j < n){
            if(nums[j] == 0){
                c0++;
            }

            while(i < n && c0 == 2){
                if(nums[i] == 0){
                    c0--;
                }
                i++;
            }

            maxi = max(maxi, j-i);
            j++;
        }
        return maxi;
    }
};
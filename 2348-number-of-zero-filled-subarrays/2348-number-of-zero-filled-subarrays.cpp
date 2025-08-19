class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;

        int i = 0;
        int j = 0;
        int n = nums.size();

        while(j < n){
            if(nums[j] == 0){
                while(j < n && nums[j] == 0){
                    j++;
                }
                int cal = j-i;

                ans += (cal * (cal+1)/2);
                i = j;
            }
            i++;
            j++; 
        }
        return ans;
    }
};
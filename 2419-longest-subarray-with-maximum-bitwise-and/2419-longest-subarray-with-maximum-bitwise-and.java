class Solution {
    public int longestSubarray(int[] nums) {
        int ans = 0;
        int maxi = Integer.MIN_VALUE;

        for(int i = 0; i<nums.length; i++){
            if(maxi < nums[i]){
                maxi = nums[i];
            }
        }

        int count =0;

        for(int i = 0; i<nums.length; i++){
            if(nums[i] == maxi){
                count++;
            }
            else{
                if(ans < count){
                    ans = count;
                }
                count = 0;
            }
        }
        if(ans < count){
            ans = count;
        }
        return ans;
    }
}
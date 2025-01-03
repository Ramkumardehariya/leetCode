class Solution {
    public int waysToSplitArray(int[] nums) {
        long right = 0;
        for(int i = 0; i<nums.length; i++){
            right += nums[i];
        }

        int ans = 0;
        long left = 0;

        for(int i = 0; i<nums.length-1; i++){
            right -= nums[i];
            left += nums[i];
            if(left >= right){
                ans++;
            }
        }

        return ans;
    }
}
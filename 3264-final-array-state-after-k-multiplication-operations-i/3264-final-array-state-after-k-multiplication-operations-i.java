class Solution {
    public int[] getFinalState(int[] nums, int k, int multiplier) {
        
        for(int i = 0; i<k; i++){
            int index = 0;
            int num = Integer.MAX_VALUE;
            for(int j = 0; j<nums.length; j++){
                if(num > nums[j]){
                    num = nums[j];
                    index = j;
                }
            }
            nums[index] = num*multiplier;
        }
        return nums;
    }
}
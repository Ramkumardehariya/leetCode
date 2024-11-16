class Solution {
    int findAns(int[] nums, int i, int j){
        int maxi = Integer.MIN_VALUE;

        for(int index = i; index < j; index++){
            if(nums[index]+1 != nums[index+1]){
                return -1;
            }
        }

        for(int index = i; index <= j; index++){
            if(nums[index] > maxi){
                maxi = nums[index];
            }
        }
        
        return maxi;
    }
    public int[] resultsArray(int[] nums, int k) {
        int ans[] = new int[nums.length-k+1];
        int index = 0;

        for(int i = 0; i<nums.length-k+1; i++){
            ans[index] = findAns(nums, i, i+k-1);
            index++;
        }
        return ans;
    }
}
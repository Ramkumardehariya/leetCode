class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        
        int n = nums.size();
        if(n==0 || n==1){
            return 0;
        }
        if(nums[0] > nums[1]){
            return 0;
        }
        if(nums[n-1] > nums[n-2]){
            return n-1;
        }

        //O(n)
        // for(int i = 1; i<n-1; i++){
        //     if(nums[i-1] < nums[i] && nums[i] > nums[i+1]){
        //         return i;
        //     }
        // }
        // return -1;

        // int n = nums.size();
        int s = 1;
        int e = n-2;

        while(s<=e){
            int mid = s+(e-s)/2;

            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                return mid;
            }
            else if(nums[mid] > nums[mid-1]){
                s = mid+1;
            }else{
                e = mid-1;
            }
        }
        return -1;
    }
};
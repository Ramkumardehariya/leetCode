class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        // int count = 0;
        // for(int i = 0; i<nums.size(); i++){
        //     if(nums[i] == 1){
        //         count++;
        //     }
        // }
        // if(count == nums.size()){
        //     return count-1;
        // }
        // count = 0;

        // int maxi = 0;

        // for(int i = 0; i<nums.size(); i++){
        //     if(nums[i] == 0){
        //         nums[i] = 1;
        //         for(int j = 0; j<nums.size(); j++){
        //             if(nums[j] == 1){
        //                 count++;
        //             }
        //             else{
        //                 maxi = max(maxi, count);
        //                 count = 0;
        //             }
        //         }
        //         if(count != 0){
        //             maxi = max(maxi, count);
        //         }
        //         nums[i] = 0;
        //     }
        // }
        // return maxi-1;

        int mx = 0;
        int c0 = 0;
        int n = nums.size();
        int i = 0;
        int j = 0;

        while(j<n){
            if(nums[j] == 0){
                c0++;
            }

            while(i<n && c0==2){
                if(nums[i] == 0){
                    c0--;
                }
                i++;
            }
            mx = max(j-i, mx);
            j++;
        }
        return mx;
    }
};
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool ans = false;
        int n = nums.size();
        int i = 0;
        int j = 0;
        
        for(; i<n-1; i++){
            if(nums[i] <= nums[i+1]){
                continue;
            }
            else{
                break;
            }
        }

        for(; j<n-1; j++){
            if(nums[j] >= nums[j+1]){
                continue;
            }
            else{
                break;
            }
        }

        if(i == n-1 || j == n-1){
            ans = true;
        }

        return ans;
    }
};
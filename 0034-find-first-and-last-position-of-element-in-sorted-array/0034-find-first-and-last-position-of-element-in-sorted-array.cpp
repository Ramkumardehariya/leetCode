class Solution {
public:

    int solve(vector<int>& nums, int target, string key){
        int s = 0;
        int e = nums.size()-1;
        int res = -1;

        while(s<=e){
            
            int mid = s+(e-s)/2;

            if(nums[mid] == target){
                res = mid;
                if(key == "FIRST"){
                    e = mid-1;
                }
                else{
                    s = mid+1;
                }
                // (find == "FIRST") ? high = mid - 1 : low = mid + 1;
            }
            else if(nums[mid] > target){
                e = mid-1;
            }
            else{
                s = mid+1;
            }

            mid = s+(e-s)/2;
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        
        return {solve(nums,target, "FIRST"), solve(nums,target, "LAST")};
        
    }
};
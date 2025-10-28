class Solution {
public:

    bool isSimulate(vector<int> nums, int start, int dir){
        int curr = start;


        while(curr >= 0 && curr < nums.size()){
            if(nums[curr] == 0){
                curr += dir;
            }
            else if(nums[curr] > 0){
                nums[curr]--;
                dir = -dir;
                curr += dir;
            }
        }

        for(int i = 0; i<nums.size(); i++){
            if(nums[i] != 0){
                return false;
            }
        }

        return true;      
    }
    int countValidSelections(vector<int>& nums) {
        int ans = 0;

        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 0){
                if(isSimulate(nums, i,-1)){
                    ans++;
                }
                if(isSimulate(nums, i, 1)){
                    ans++;
                }
            }
        }
        return ans;
    }
};
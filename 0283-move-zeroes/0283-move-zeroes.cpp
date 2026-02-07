class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int n = nums.size();

        while(j < n && i < n){
            while(i < n && nums[i] != 0){
                i++;
            }
            while(j < n && nums[j] == 0){
                j++;
            }
            if(j == n || i == n){
                break;
            }
            swap(nums[i], nums[j]);
        }

    }
};
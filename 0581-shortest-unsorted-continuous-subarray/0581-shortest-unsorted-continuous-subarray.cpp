class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp = nums;
        sort(nums.begin() , nums.end());
        int n = nums.size();
        int i = 0; 
        int j = nums.size()-1;

        while(i < nums.size() && temp[i] == nums[i]){
            i++;
        }

        while(j >= 0 && nums[j] == temp[j]){
            j--;
        }

        if(i > nums.size()-1 || j < 0){
            return 0;
        }

        return j-i+1;
    }
};
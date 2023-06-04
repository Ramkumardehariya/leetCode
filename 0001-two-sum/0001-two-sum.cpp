class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int a = 0;
        int b = 0;

        for(int i = 0; i < nums.size()-1; i++)
        {
            for(int j = i+1; j<nums.size(); j++)
            {
               if(target == nums[i] + nums[j]){
                   a = i;
                   b = j;

               }

            }
        }
        return {a,b};
    }
};
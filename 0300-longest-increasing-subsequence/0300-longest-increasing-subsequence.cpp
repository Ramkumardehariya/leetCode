class Solution {
public:

    int spaceOptimize(vector<int> &nums, int n){
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);

        for(int curr = n-1; curr>=0; curr--){
            for(int prev = curr-1; prev>=-1; prev--){

                int include = 0;
                if(prev == -1 || nums[curr] > nums[prev]){
                    include = 1 + nextRow[curr+1];
                }

                int exclude = nextRow[prev+1];

                currRow[prev+1] = max(include, exclude);

            }
            nextRow = currRow;
        }
        return nextRow[0];
    }
    int lengthOfLIS(vector<int>& nums) {
        //space optimize
        int n = nums.size();
        return spaceOptimize(nums, n);
    }
};
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        vector<vector<int>> subset;
        int n = nums.size();

        for(int i = 0; i < (1 << n); i++) {
            vector<int> temp;
            for(int j = 0; j < n; j++) {
                if((i & (1 << j)) != 0) {
                    temp.push_back(nums[j]);
                }
            }
            subset.push_back(temp);
        }

        for(int i = 0; i<subset.size(); i++){
            int sum = 0;
            for(int j = 0; j<subset[i].size(); j++){
                sum ^= subset[i][j];
            }
            ans += sum;
        }

        return ans;
    }
};
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size();
        
        vector<vector<int>> temp;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<(int)nums[i].size(); j++){
                temp.push_back({i+j,j, nums[i][j]});
            }
        }

        sort(temp.begin(), temp.end());

        vector<int> ans;

        for(int i = 0; i<temp.size(); i++){
            ans.push_back(temp[i][2]);
        }

        return ans;
    }
};
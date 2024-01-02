class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(auto it : nums){
            mp[it]++;
        }

        int maxRow = 0;

        for(auto it : mp){
            if(it.second > maxRow){
                maxRow = it.second;
            }
        }

        vector<vector<int>> ans;

        for(int i = 1; i<=maxRow; i++){
            vector<int> temp;
            for(auto it : mp){
                if(it.second >= i){
                    temp.push_back(it.first);
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
};
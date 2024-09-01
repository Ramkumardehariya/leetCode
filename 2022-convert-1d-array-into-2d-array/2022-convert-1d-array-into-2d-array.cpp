class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        int count = 1;

        for(int i = 0; i<original.size(); i++){
            temp.push_back(original[i]);
            if(count % n == 0){
                ans.push_back(temp);
                temp.clear();
                count = 0;
            }
            count++;
        }
        if(count > 1){
            ans.push_back(temp);
        }
        if(ans.size() < m || ans.size() > m || ans[0].size() > n || ans[0].size() < n){
            ans.clear();
        }
        return ans;
    }
};
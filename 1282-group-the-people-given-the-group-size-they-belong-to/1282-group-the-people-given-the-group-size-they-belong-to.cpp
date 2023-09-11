class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        int n = groupSizes.size();

        for(int i = 1; i<=n; i++){
            vector<int> temp;
            for(int j = 0; j<n; j++){
                if(groupSizes[j] == i){
                    if(temp.size() >=i){
                        ans.push_back(temp);
                        temp.clear();
                    }
                    temp.push_back(j);
                }
            }
            if(temp.size()){
                ans.push_back(temp);
            }
        }

        return ans;
    }
};
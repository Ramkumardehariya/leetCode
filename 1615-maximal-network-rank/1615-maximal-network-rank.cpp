class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> vec(n);

        for(auto it : roads){
            vec[it[0]].insert(it[1]);
            vec[it[1]].insert(it[0]);
        }

        int maxi = 0;
        int count = 0;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                count = vec[i].size();
                count += vec[j].size();
                if(vec[j].count(i)){
                    count--;
                }
                maxi = max(maxi, count);
            }
        }
        return maxi;
    }
};
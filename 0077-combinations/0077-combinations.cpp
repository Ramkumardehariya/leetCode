class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int> temp, int start, int n, int k){
        if(temp.size() > k){
            return ;
        }
        if(temp.size() == k){
            ans.push_back(temp);
        }

        for(int i = start; i<=n; i++){
            temp.push_back(i);
            solve(temp, i+1, n, k);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;

        solve(temp, 1, n, k);
        return ans;
    }
};
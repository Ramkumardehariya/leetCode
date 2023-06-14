class Solution {
public:

    void solve(vector<vector<int>> &ans, vector<int> &temp, int n, int k , int index, int sum){
        if(sum == n && k == 0){
            ans.push_back(temp);
            return;
        }
        if(sum > n){
            return;
        }

        for(int i = index; i<=9; i++){
            if(i>n){
                break;
            }
            temp.push_back(i);
            solve(ans, temp, n, k-1, i+1, sum+i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(ans, temp, n, k, 1, 0);

        return ans;

    }
};
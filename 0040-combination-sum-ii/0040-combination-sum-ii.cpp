class Solution {
public:

    void solve(vector<vector<int>> &ans, vector<int> &temp, vector<int> &arr, int target, int index){
       
            if(target == 0){
                ans.push_back(temp);
                return;
            }
            
        
        for(int i = index; i<arr.size(); i++){

            if(i > index && arr[i] == arr[i-1]){
                continue;
            }

            if(arr[i] > target){
                break;
            }
        
            temp.push_back(arr[i]);
            solve(ans, temp, arr, target-arr[i], i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = candidates.size();
        vector<int> visited(n,0);
        sort(candidates.begin(),candidates.end());

        solve(ans, temp, candidates, target, 0);

        return ans;
    }
};
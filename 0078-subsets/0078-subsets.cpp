class Solution {
public:
    void solve(vector<int> arr, int index, vector<int> temp, vector<vector<int>> &ans){
        if(index >= arr.size()){
            ans.push_back(temp);
            temp.clear();
            return;
        }

        solve(arr, index+1, temp, ans);
        temp.push_back(arr[index]);
        solve(arr,index+1, temp, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(nums, 0, temp, ans);
        return ans;
    }
};
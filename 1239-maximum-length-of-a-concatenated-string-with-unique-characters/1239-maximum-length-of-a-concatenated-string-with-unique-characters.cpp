class Solution {
public:
    int solve(int index, vector<string> &ans, vector<string> &arr){
        if(index >= arr.size()){
            return 0;
        }

        ans.push_back(arr[index]);
        unordered_map<char,int> mp;

        for(auto it : ans){
            for(auto it1: it){
                mp[it1]++;
            }
        }
        bool flag = 1;
        for(auto it : mp){
            if(it.second > 1){
                flag = 0;
                break;
            }
        }
        int op1 = 0;
        int op2 = 0;

        if(flag){
            op1 += arr[index].size() + solve(index+1, ans, arr);
        }
        ans.pop_back();
        op2 = solve(index+1, ans, arr);
        return max(op1,op2);
    }
    int maxLength(vector<string>& arr) {
        vector<string> ans;

        return solve(0, ans, arr);
    }
};
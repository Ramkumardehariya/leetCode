class Solution {
public:
    int solve(vector<int> &arr){
    
        int mini = 1e9;
        int maxi = -1;

        for(int i = 0; i<26; i++){
            maxi = max(maxi, arr[i]);
            if(arr[i] >= 1){
                mini = min(mini, arr[i]);
            }
        }

        return maxi-mini;
    }
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i<n; i++){
            vector<int> arr(26, 0);
            for(int j = i; j<n; j++){
                arr[s[j]-'a']++;
                ans = ans + solve(arr);
            }
        }
        return ans;
    }
};
class Solution {
public:
    int solve(int i, vector<vector<int>>& arr, int k, vector<vector<int>> &dp){
        if(i == arr.size() || k==0){
            return 0;
        }
        if(dp[i][k] != -1){
            return dp[i][k];
        }

        int s= i+1, e = arr.size()-1, val = arr[i][2];

        while(s<=e){
            int m = s + (e-s)/2;

            if(arr[m][0] > arr[i][1]){
                e = m-1;
            }
            else{
                s = m+1;
            }
        }

        int take = val + solve(s, arr, k-1, dp);
        int notTake = 0 + solve(i+1, arr, k, dp);

       return dp[i][k] = max(take, notTake);
    }
    int maxValue(vector<vector<int>>& events, int k) {

        sort(events.begin(), events.end());
        int n = events.size();

        //memoization
        vector<vector<int>> dp(n, vector<int> (k+1,-1));
        return solve(0,events, k, dp);
    }
};
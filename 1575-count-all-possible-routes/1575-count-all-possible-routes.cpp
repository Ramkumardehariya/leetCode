class Solution {
public:
    int mod = 1000000007;
    int solve(int current, int &finish, vector<int> &arr, int fuel, vector<vector<int>> &dp){
        int n = arr.size();
        if(fuel < 0){
            return 0;
        }

        if(dp[current][fuel] != -1){
            return dp[current][fuel];
        }
        
        
        int ans = 0;
        if(current == finish){
            ans++;
        }
        for(int next = 0; next<n; next++){
            if(next != current){
                ans =  (ans + solve(next, finish, arr, (fuel-abs(arr[current]-arr[next]))%mod, dp))%mod;
            }
        }
        return dp[current][fuel] =  ans%mod;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();

        vector<vector<int>> dp(n, vector<int> (fuel+1, -1));
        return solve(start , finish , locations, fuel, dp);
    }
};
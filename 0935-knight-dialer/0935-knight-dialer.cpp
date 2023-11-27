class Solution {
public:
      int mod = 1e9+7;

     

    int rec(int n, int ind, map<int,vector<int>>& mp, vector<vector<int>>& dp){
      if(n==1) return 1;
      if(dp[n][ind]!=-1) return dp[n][ind];
      vector<int> cur = mp[ind];
      int val = 0;
      for(int i=0;i<cur.size();i++){
        val+=(rec(n-1,cur[i],mp,dp));
        val%=mod;
      }
      return dp[n][ind] = val%mod;
    }

    int knightDialer(int n) {
      map<int, vector<int>> mp;
      mp[1] = {8,6};
      mp[2] = {7,9};
      mp[3] = {4,8};
      mp[4] = {3,9,0};
      mp[5] = {};
      mp[6] = {1,7,0};
      mp[7] = {2,6};
      mp[8] = {1,3};
      mp[9] = {2,4};
      mp[0] = {4,6};
      vector<vector<int>> dp(n+1, vector<int>(10,-1));
      int ans = 0;
      for(int i=0;i<10;i++){
        ans+=rec(n,i,mp,dp);
        ans%=mod;
      }
      return ans;
    }
};
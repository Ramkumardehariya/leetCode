class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

        int sum1 = 0;
        int sum2 = 0;

        for(auto num : s1){
            sum1 += num;
        }
        for(auto num : s2){
            sum2 += num;
        }

        for(int i = 1; i<n+1; i++){
            for(int j = 1; j<m+1; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = s1[i-1] + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }

        return sum1+sum2-2*dp[n][m];
    }
};
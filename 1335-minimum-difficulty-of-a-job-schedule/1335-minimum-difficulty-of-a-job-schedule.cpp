class Solution {
public:
    int dp[300][11];

    int solve(vector<int>& jobD, int n, int d, int i){
        if(d == 1){
            return *max_element(begin(jobD)+i, end(jobD));
        }

        if(dp[i][d] != -1){
            return dp[i][d];
        }

        int result = INT_MAX;
        int currD = INT_MIN;

        for(int j = i; j<=n-d; j++){
            currD = max(currD, jobD[j]);
            result = min(result, currD + solve(jobD, n, d-1, j+1));
        }

        return dp[i][d] = result;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        memset(dp,-1,sizeof(dp));
        int n = jobDifficulty.size(); 

        if(n < d){
            return -1;
        }


        return solve(jobDifficulty, n, d, 0);
    }
};
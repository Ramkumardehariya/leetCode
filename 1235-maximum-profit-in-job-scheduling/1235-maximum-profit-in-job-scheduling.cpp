class Solution {
public:
    int solve(int i , vector<int> &startTime, vector<vector<int>> &job,int n, vector<int> &dp){
        if(i >= n){
            return 0;
        }
        
        if(dp[i] != -1){
            return dp[i];
        }

        int index = lower_bound(startTime.begin(), startTime.end(),job[i][1])-startTime.begin();
        int pic = job[i][2] + solve(index, startTime, job,n, dp);
        int notPic = solve(i+1, startTime, job,n, dp);

        return dp[i] = max(pic,notPic);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<int> dp(n,-1);
        vector<vector<int>>job;

        for(int i = 0; i<n; i++){
            job.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(job.begin(),job.end());
        sort(startTime.begin(),startTime.end());
        return solve(0, startTime, job,n, dp);
    }
};
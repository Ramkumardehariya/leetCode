class Solution {
public:
    int solve(vector<int> &obs, int currpos, int currlane, vector<vector<int>> &dp){
        if(currpos == obs.size()-1){
            return 0;
        }
        if(dp[currlane][currpos] != -1){
            return dp[currlane][currpos];
        }

        int finalAns = INT_MAX;
        if(obs[currpos+1] != currlane){
            finalAns = solve(obs, currpos+1, currlane, dp);
        }
        else{
            for(int i = 1; i<=3; i++){
                if(i != currlane && obs[currpos] != i){
                    finalAns = min(finalAns, 1+solve(obs, currpos, i, dp));
                }
            }
        }
        return dp[currlane][currpos] = finalAns;
    }
    int minSideJumps(vector<int>& obstacles) {
        int currpos = 0;
        int currlane = 2;
        vector<vector<int>> dp(4,vector<int>(obstacles.size(), -1));
        return solve(obstacles, currpos, currlane, dp);
    }
};
const int N = 1e9 + 7;
class Solution {
public:
    int n , m, k;
    int solve(int index, int score, int max_num, vector<vector<vector<int>>> &dp){
        if(n == index && k == score){
            return 1;
        }
        if(n == index || k < score){
            return 0;
        }

        if(dp[index][score][max_num] != -1){
            return dp[index][score][max_num];
        }
        int ans = 0;
        for(int curr = 1; curr <=m; curr++){
            if(curr <= max_num){
                ans += solve(index + 1, score, max_num, dp);
            }
            else{
                ans += solve(index +1, score+1, curr, dp);
            }
            ans = ans % N;
        }
        return dp[index][score][max_num] = ans;
    }

    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<int>>> dp(n+2, vector<vector<int>> (k+2, vector<int> (m+2, -1)));

        this->n = n;
        this->m = m;
        this->k = k;
        return solve(0, 0, 0, dp);
    }
};
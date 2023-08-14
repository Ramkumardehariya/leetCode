class Solution {
public:

    bool dfs(int i, vector<int> &ms, int side, vector<int> &v, int n){
        if(i == n){
            return v[0] == v[1] && v[1] == v[2] && v[2] == v[3];
        }

        for(int k = 0; k<4; k++){
            if(v[k] + ms[i] > side){
                continue;
            }
            v[k] += ms[i];
            if(dfs(i+1, ms, side, v, n)){
                return true;
            }
            v[k] -= ms[i];
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int s = accumulate(matchsticks.begin(),matchsticks.end(), 0);
        int n = matchsticks.size();

        if(s%4){
            return false;
        }
        sort(matchsticks.begin(), matchsticks.end(), greater<int> ());
        int side = s/4;
        vector<int> v(4);

        return dfs(0, matchsticks, side, v, n);
    }
};
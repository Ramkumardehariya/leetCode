class Solution {
public:
    void calculate(int n, int pos, int &count, vector<bool> &vis){
        if(pos > n){
            count++;
        }
        for(int i = 1; i<=n; ++i){
            if(!vis[i] && (i%pos == 0 || pos%i == 0)){
                vis[i] = true;
                calculate(n, pos+1, count, vis);
                vis[i] = false;
            }
        }
    }
    int countArrangement(int n) {
        vector<bool> vis(n+1, false);
        int count = 0;
        calculate(n, 1, count, vis);
        return count;
    }
};
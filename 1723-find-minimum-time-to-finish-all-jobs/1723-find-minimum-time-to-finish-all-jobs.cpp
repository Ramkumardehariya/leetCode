class Solution {
public:

    void solve(int i, int &k, vector<int> &jobs, vector<int> &work, int &ans){
        if(i == jobs.size()){
            ans = min(*max_element(work.begin(), work.end()), ans);
            return;
        }

        if((*max_element(work.begin(), work.end()) >= ans)){
            return;
        }

        for(int j = 0; j<k; j++){
            if(j > 0 && work[j] == work[j-1]){
                continue;
            }
            work[j] += jobs[i];
            solve(i+1, k, jobs, work, ans);
            work[j] -= jobs[i];
        }
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int ans = INT_MAX;
        vector<int> work(k, 0);
        solve(0, k, jobs, work, ans);
        return ans;
    }
};
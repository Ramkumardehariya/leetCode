class Solution {
public:

    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        
        if(k == 1){
            return 0;
        }

        vector<long long> ans;

        for(int i = 1; i<n; i++){
            ans.push_back(weights[i-1] + weights[i]);
        }

        sort(ans.begin(), ans.end());

        long long mini = 0;
        long long maxi = 0;
        
        for(int i = 0; i+1<k; i++){
            mini += ans[i];
            maxi += ans[ans.size()-1-i];
        }

        return maxi-mini;
    }
};
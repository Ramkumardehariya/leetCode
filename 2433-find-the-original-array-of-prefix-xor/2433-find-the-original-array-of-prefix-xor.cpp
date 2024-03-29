class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n=pref.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
            if(i==0)
                ans[0]=pref[0];
            else
                ans[i]=pref[i]^pref[i-1];
        }
        return ans;
    }
};
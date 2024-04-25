class Solution {
public:
    int longestIdealString(string &s, int k) {
        int mp[26]={};
        for(auto c: s){
            int mx=0, x=c-'a';
            for(int i=max(x-k, 0); i<=min(x+k, 25); i++)
                mx=max(mx, mp[i]);
            mp[x]=1+mx;
        }
        return *max_element(mp, mp+26);
    }
};
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int cookies = 0;
        int greed = 0;

        while(cookies < m && greed < n){
            if(s[cookies] >= g[greed]){
                greed++;
            }
            cookies++;
        }
        return greed; 
    }
};
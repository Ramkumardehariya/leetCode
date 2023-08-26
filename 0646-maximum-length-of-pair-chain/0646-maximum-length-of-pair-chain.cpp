class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), comp);

        int n = pairs.size();
        int ans = 0;
        int check = -1e9;
        for(auto pair : pairs){
            if(pair[0] > check){
                check  = pair[1];
                ans++;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& G, int k) {
        int n = G.size(), m = G[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            G[i][j] += G[i][j - 1];
        }
    }

    int ans = 0;
    for (int l = 0; l < m; l++) {
        for (int r = l; r < m; r++) {
            int sum = 0;
            unordered_map<int, int> mp;
            ++mp[sum];
            for (int i = 0; i < n; i++) {
                sum += G[i][r] - (l - 1 >= 0 ? G[i][l - 1] : 0);
                if (mp.find(sum - k) != mp.end()) {
                    ans += mp[sum - k];
                }
                ++mp[sum];
            }
        }
    }

    return ans;
    }
};
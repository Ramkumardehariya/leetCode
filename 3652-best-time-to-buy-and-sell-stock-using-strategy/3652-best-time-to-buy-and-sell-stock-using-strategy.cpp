class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = (int)prices.size();
        long long base = 0;
        for (int i = 0; i < n; ++i) base += 1LL * strategy[i] * prices[i];

        // Initial window [0, k-1]
        long long curSP = 0;                       // sum of S[i]*P[i] over window
        long long curP2 = 0;                       // sum of prices over second half
        for (int i = 0; i < k; ++i) curSP += 1LL * strategy[i] * prices[i];
        for (int i = k/2; i < k; ++i) curP2 += prices[i];

        long long bestGain = -curSP + curP2;

        // Slide windows starting at l = 1..n-k
        for (int l = 1; l + k - 1 < n; ++l) {
            int outIdx = l - 1;         // leaving index
            int inIdx  = l + k - 1;     // entering index

            // update SP over full window
            curSP -= 1LL * strategy[outIdx] * prices[outIdx];
            curSP += 1LL * strategy[inIdx]  * prices[inIdx];

            // update sum over second half: [l + k/2, l + k - 1]
            curP2 -= prices[l - 1 + k/2];
            curP2 += prices[inIdx];

            bestGain = max(bestGain, -curSP + curP2);
        }

        return base + max(0LL, bestGain);
    }
};
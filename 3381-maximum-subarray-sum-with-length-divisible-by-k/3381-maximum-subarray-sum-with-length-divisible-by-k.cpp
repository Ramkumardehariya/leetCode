class Solution {
public:
    using ll = long long;
    long long maxSubarraySum(vector<int>& nums, int k) {
        ll prefSum = 0; // current prefix sum
        ll subMax = LLONG_MIN; // max subarray sum with length divisible by k

        // minSoFar[m] stores the minimum prefix sum for indices ≡ m (mod k)
        vector<ll> minSoFar(k, LLONG_MAX / 2);
        minSoFar[(k - 1) % k] = 0; // prefix sum before first element

        for (int i = 0; i < nums.size(); i++) {
            prefSum += nums[i];
            subMax = max(subMax, prefSum - minSoFar[i % k]); // candidate max
            minSoFar[i % k] = min(minSoFar[i % k], prefSum); // update min prefix
        }

        return subMax;
    }
};
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        vector<int> buckets(limit + 1, 0);
        int start = 0;
        int end = buckets.size() - 1;
        int boats = 0;

        for (int weight : people) {
            buckets[weight]++;
        }

        while (start <= end) {
            while (start <= end && buckets[start] <= 0) {
                start++;
            }

            while (start <= end && buckets[end] <= 0) {
                end--;
            }

            if (buckets[start] <= 0 && buckets[end] <= 0) {
                break;
            }

            boats++;

            if (start + end <= limit) {
                buckets[start]--;
            }

            buckets[end]--;
        }

        return boats;
    }
};
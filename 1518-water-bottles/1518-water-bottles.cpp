class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;

        while(numBottles >= numExchange){
            int rem = numBottles%numExchange;
            ans += numBottles/numExchange;
            numBottles = (numBottles/numExchange) + rem;
        }
        return ans;
    }
};
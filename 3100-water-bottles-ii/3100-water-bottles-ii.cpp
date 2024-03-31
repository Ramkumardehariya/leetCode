class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans=numBottles;
        int rem=numBottles;
        while(rem>0){
            if (rem>=numExchange){
                rem-=numExchange;
                ans++;
                rem++;
                numExchange++;
            }
            else{
                break;
            }
        }
        return ans;
    }
};
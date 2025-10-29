class Solution {
public:
    int smallestNumber(int n) {
        int ans = 0;

        while(n > 0){
            n = n>>1;
            ans = ans<<1 | 1;
        }
        return ans;
    }
};
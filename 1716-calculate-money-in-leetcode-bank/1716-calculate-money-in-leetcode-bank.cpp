class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        int count = 1;
        int week = 1;
        for(int i = 1; i<=n; i++){
            if(i%7 == 0){
                week++;
                ans += count;
                count = week;
                continue;
            }
            ans += count;
            count++;
        }
        return ans;
    }
};
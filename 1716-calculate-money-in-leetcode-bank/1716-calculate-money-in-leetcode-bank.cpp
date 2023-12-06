class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        int count = 1;
        int check = 1;

        for(int i = 1; i<=n; i++){
            ans += count;

            if(i%7 == 0){
                count = check;
                check++;
            }
            count++;
        }
        return ans;
    }
};
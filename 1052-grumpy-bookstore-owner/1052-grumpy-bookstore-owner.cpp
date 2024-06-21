class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int m) {
        int ans = 0;
        int maxi = 0;
        int sum = 0;
        int c =0;

        for(int i = 0; i<customers.size(); i++){
            c++;
            if(grumpy[i] == 0){
                ans += customers[i];
            }
            else{
                sum += customers[i];
            }
            if(c > m){
                c--;
                if(grumpy[i-c] != 0){
                    sum -= customers[i-c];
                }
            }
            maxi = max(maxi, sum);
        }
        return ans+maxi;
    }
};
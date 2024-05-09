class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;
        sort(happiness.rbegin(), happiness.rend());

        for(int i = 0; i<k; i++){
            long long currH = happiness[i];

            if(currH-i > 0){
                ans += currH-i;
            }
            cout<<currH-i<<" ";
        }

        return ans;
    }
};
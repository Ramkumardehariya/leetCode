class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;
        priority_queue<int> pq;

        for(auto num: happiness){
            pq.push(num);
        }
        int count = 0;
        while(k != 0){
            int num = pq.top();
            pq.pop();
            if(num-count >= 0){
                ans += (num-count);
            }
            else{
                break;
            }
            k--;
            count++;
        }

        return ans;
    }
};
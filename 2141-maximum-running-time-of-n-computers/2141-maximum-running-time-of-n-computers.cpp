class Solution {
public:

    bool isPossible(int n, vector<int> &batteries, long long avg){
        long long sum = 0;

        for(auto ele : batteries){
            if(ele <= avg){
                sum += ele;
            }
            else{
                sum += avg;
            }
        }

        return sum >= avg*n;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = 0;
        long long ans = 0;

        for(auto i : batteries){
            sum += i;
        }

        long long start = 0;
        long long end = sum;

        while(start <= end){
            long long avgTime = (start + end)/2;

            if(isPossible(n, batteries, avgTime)){
                ans = avgTime;
                start = avgTime + 1;
            }
            else{
                end = avgTime - 1;
            }
        }

        return ans;
    }
};
class Solution {
public:

    int possible(vector<int> &arr, int day, int m, int k){
        int count = 0;
        int noOfB = 0;

        for(int i = 0; i<arr.size(); i++){
            if(arr[i] <= day){
                count++;
            }
            else{
                noOfB += (count/k);
                count = 0;
            }
        }
        noOfB += (count/k);
        return noOfB >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = (long long)m*(long long)k;

        if(val > bloomDay.size()){
            return -1;
        }
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int i = 0; i<bloomDay.size(); i++){
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }

        int low = mini;
        int high = maxi;

        while(low <= high){
            int mid = (low+high)/2;

            if(possible(bloomDay, mid, m, k)){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        // for(int i = mini; i<=maxi; i++){
        //     if(possible(bloomDay, i, m, k)){
        //         return i;
        //     }
        // }

        return low;
    }
};
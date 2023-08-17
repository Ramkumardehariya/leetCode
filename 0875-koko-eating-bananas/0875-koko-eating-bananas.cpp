class Solution {
public:

    int findMax(vector<int> &piles){
        int maxi = INT_MIN;
        for(int i = 0; i<piles.size(); i++){
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }

    long long calculateTime(vector<int> &piles, int hour){
        long long totalH = 0;

        for(int i = 0; i<piles.size(); i++){
            totalH += ceil((double)(piles[i])/(double)(hour));
        }
        return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = findMax(piles);
        int low = 1;

        while(low <= high){
            int mid = (low+high)/2;

            long long totalH = calculateTime(piles, mid);

            if(totalH <= h){
                high = mid-1;
            }
            else{
                low = mid+1;
            }

            
        }
        
        return low;
    }
};
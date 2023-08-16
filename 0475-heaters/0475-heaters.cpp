class Solution {
public:

    bool isValid(vector<int>& houses, vector<int>& heaters, int mid){
        int m = houses.size();
        int n = heaters.size();
        int i = 0;
        int j = 0;

        while(i < n && j < m){
            if(abs(heaters[i]-houses[j]) <= mid){
                j++;
            }
            else{
                i++;
            }
        }
        if(i < n){
            return true;
        }

        return false;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int s = 0;
        int e = 1e9;
        int ans = -1;

        while(s <= e){
            int mid = s+ (e-s)/2;
            if(isValid(houses, heaters, mid)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
};
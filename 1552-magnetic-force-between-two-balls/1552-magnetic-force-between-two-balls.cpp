class Solution {
public:

    bool possible(vector<int> &arr , int m, int mid){
        int place = 1;
        int prev = arr[0];
        for(int i = 1; i<arr.size(); i++){
            if((arr[i]-prev) >= mid){
                prev = arr[i];
                place++;
                if(place == m){
                    return true;
                }
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int ans = 0;
        int n = position.size();
        long long s = 0;
        long long e = position[n-1];

        while(s <= e){
            int mid = s+(e-s)/2;
            if(possible(position, m, mid)){
                ans = mid;
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }

        return ans;
    }
};
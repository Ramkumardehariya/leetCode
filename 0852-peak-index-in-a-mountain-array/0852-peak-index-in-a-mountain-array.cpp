class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // int ans = 0;
        // int n = arr.size();
        // for(int i = 0; i<n-1; i++){
        //     if(arr[i] > arr[i+1]){
        //         ans = i;
        //         break;
        //     }
        // }
        // return ans;

        int low = 0;
        int high = arr.size()-1;

        while(low < high){
            int mid = low + (high - low)/2;

            if(arr[mid] < arr[mid+1]){
                low = mid+1;
            }
            else{
              high = mid;  
            }
        }

        return low;
    }
};
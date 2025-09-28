class Solution {
public:
    int largestPerimeter(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();

        for(int i = 0; i<n-2; i++){
            for(int j = i+1; j<n-1; j++){
                for(int k = j+1; k<n; k++){
                    if(arr[i]+arr[j] > arr[k] && arr[i]+arr[k] > arr[j] && arr[j]+arr[k] > arr[i] && arr[i]+arr[j]+arr[k] > ans){
                        ans = arr[i]+arr[j]+arr[k];
                    }
                }
            }
        }
        return ans;
    }
};
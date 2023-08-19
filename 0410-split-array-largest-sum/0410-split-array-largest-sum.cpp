class Solution {
public:

    bool canPossible(vector<int> &arr, int num, int k){
        int sum = 0;
        int count =1;

        for(int i = 0; i<arr.size(); i++){
            sum += arr[i];
            if(sum <= num){
                continue;
            }
            else{
                sum = 0;
                count += 1;
                sum += arr[i];
            }
            if(count > k){
                return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(),nums.end(), 0);

        while(low <= high){
            int mid = (low+high)/2;

            if(canPossible(nums, mid, k) == true){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};
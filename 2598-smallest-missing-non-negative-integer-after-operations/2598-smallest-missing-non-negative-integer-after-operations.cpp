class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> arr(value, 0);

        for(auto num: nums){
            arr[((num%value)+value)%value]++;
        }

        int ans = 0;

        while(arr[ans%value] > 0){
            arr[ans%value]--;
            ans++;
        }

        return ans;
    }
};
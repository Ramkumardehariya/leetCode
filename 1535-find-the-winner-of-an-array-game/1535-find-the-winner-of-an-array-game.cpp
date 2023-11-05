class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int ans = arr[0];
        int count = 0;

        for(int i = 1; i<arr.size(); i++){
            if(ans > arr[i]){
                count++;
            }
            else{
                count = 1;
                ans = arr[i];
            }

            if(count == k){
                return ans;
            }
        }

        return ans;
    }
};
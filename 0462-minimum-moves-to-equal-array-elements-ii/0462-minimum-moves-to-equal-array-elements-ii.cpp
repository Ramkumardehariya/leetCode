class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // int mini = INT_MAX;
        // int n = nums.size();

        // for(int i = 0; i<n; i++){
        //     long long sum = 0;
        //     for(int j = 0; j<n; j++){
        //         int diff = abs(nums[i]-nums[j]);
        //         sum += diff;
        //     }
        //     if(sum < mini){
        //         mini = sum;
        //     }
        // }
        // return mini;

        sort(nums.begin(), nums.end());
        int num = nums[nums.size()/2];
        int ans = 0;

        for(auto it : nums){
            ans += abs(it-num);
        }
        
        return ans;
    }
};
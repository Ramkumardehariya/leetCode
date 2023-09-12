class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        vector<bool> vis(n);

        for(int i = 0; i<n; i++){
            int count = 0;
            while(!vis[i]){
                vis[i] = 1;
                count++;
                i = nums[i];
            }
            ans = max(ans,count);
        }
    return ans;
    }
};
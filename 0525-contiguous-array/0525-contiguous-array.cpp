class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans = 0;
        unordered_map<int,int> mp;
        int sum = 0;
        // mp[0] = 0;

        for(int i = 0; i<nums.size(); i++){
            // cout<<sum<<" ";
            if(nums[i] == 1){
                sum += nums[i];
            }
            else{
                sum += -1;
            }

            if(sum == 0){
                ans = max(ans, i+1);
            }

            if(mp.find(sum) == mp.end()){
                mp[sum] = i;
            }
            else{
                ans = max(ans, i-mp[sum]);
            }
        }
        return ans;
    }
};
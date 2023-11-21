class Solution {
public:
    int mod = 1000000007;

    int reverse(int num){
        int rev = 0;

        while(num){
            rev = rev*10 + num%10;
            num = num/10;
        }

        return rev;
    }
    int countNicePairs(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        unordered_map<int,int> mp;

        for(int i = 0; i<n; i++){
            int diff = nums[i] - reverse(nums[i]);
            if(mp.count(diff) == true){
                ans = (ans + mp[diff])%mod;
            }
            mp[diff]++;
        }
        
        return ans%mod;
    }
};
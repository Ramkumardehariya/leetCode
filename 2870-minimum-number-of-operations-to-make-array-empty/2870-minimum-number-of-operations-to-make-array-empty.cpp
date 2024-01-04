class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans = 0;

        for(auto it : nums){
            mp[it]++;
        }

        for(auto it : mp){
            int num = it.second;

            if(num == 1){
                return -1;
            }
            else if(num %3 == 0){
                ans += (num/3);
            }
            else{
                ans += (num/3)+1;
            }
            
        }
        return ans;
    }
};
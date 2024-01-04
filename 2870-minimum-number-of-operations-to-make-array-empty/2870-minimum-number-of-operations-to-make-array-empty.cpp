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
            else if(num%2 == 0 && num%3 == 1){
                ans += (num/3)+1;
            }
            else if(num%2==1 && num%3 == 2){
                ans += (num/3)+1;
            }
            else if(num % 3 == 1 && num % 2 == 1){
                ans += (num/3)+1;
            }
            else if(num % 3 == 2 && num % 2 == 0){
                ans += (num/3)+1;
            }
            else if(num %3 == 0){
                ans += (num/3);
            }
            
        }
        return ans;
    }
};
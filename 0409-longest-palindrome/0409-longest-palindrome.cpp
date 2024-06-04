class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;

        for(auto ch : s){
            mp[ch]++;
        }

        int ans = 0;
        for(auto ch : mp){
            ans += ch.second/2;
        }
        ans *= 2;
        
        if(ans%2 == 0){
            if(s.size() > ans){
                ans += 1;
            }
        }
        return ans;
    }
};
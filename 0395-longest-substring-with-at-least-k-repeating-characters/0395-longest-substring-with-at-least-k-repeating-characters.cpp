class Solution {
public:
    int longestSubstring(string s, int k) {
        
        int n = s.size();


        if(n < k || n==0){
            return 0;
        }

        if(k <= 1){
            return n;
        }

        int left = 0;

        unordered_map<char, int> mp;

        for(auto ch : s){
            mp[ch]++;
        }

        while(left < n && mp[s[left]] >= k){
            left++;
        }

        if(left >= n-1){
            return left;
        }

        int a = longestSubstring(s.substr(0, left), k);

        while(left < n && mp[s[left]] < k){
            left++;
        }

        int b = left < n ? longestSubstring(s.substr(left), k) : 0;

        return max(a, b);
        
    }
};
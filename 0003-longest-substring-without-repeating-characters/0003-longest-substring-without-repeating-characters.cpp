class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() < 2){
            return s.size();
        }
        int i = 0;
        int j = 0;
        int ans = 1;
        
        unordered_map<char,int> mp;

        while(j < s.size()){
            mp[s[j]]++;
            
            while(mp[s[j]] > 1){
                mp[s[i]]--;
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }

        return ans;
    }
};
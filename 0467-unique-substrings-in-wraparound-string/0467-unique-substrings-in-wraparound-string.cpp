class Solution {
public:
    int findSubstringInWraproundString(string s) {
        unordered_map<char,int> mp;
        mp[s[0]] = 1;
        int n = s.size();
        int pos = 1;

        for(int i = 1; i<s.size(); i++){

            if((s[i]-'0') - (s[i-1]-'0') == 1 or (s[i] == 'a' and s[i-1]=='z')){
                pos++;
            }
            else{
                pos = 1;
            }

            if(pos > mp[s[i]]){
                mp[s[i]] = pos;
            }
        }

        int ans = 0;
        for(auto it : mp){
            ans += it.second;
        }

        return ans;
    }
};
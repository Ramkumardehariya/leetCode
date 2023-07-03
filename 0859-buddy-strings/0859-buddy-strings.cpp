class Solution {
public:
    bool buddyStrings(string s, string goal) {
        unordered_map<char,int> mp;
        for(int i =0; i<s.size(); i++){
            mp[s[i]] = i;
        }
        for(int i = 0; i<goal.size(); i++){
            if(mp.find(goal[i]) == mp.end()){
                return false;
            }
            if(mp[goal[i]] != i){
                swap(s[i], s[mp[goal[i]]]);
                if(s == goal){
                    return true;
                }
                swap(s[i], s[mp[goal[i]]]);
            }
        }
        return false;
    }
};
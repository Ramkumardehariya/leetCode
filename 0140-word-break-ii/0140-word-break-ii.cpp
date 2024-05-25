class Solution {
public:
    void backtrack(string s, int index,unordered_set<string> st, vector<string> &ans, string curr){
        if(index == s.length()){
            ans.push_back(curr);
        }
        string t = "";
        for(int i = index; i<s.length(); i++){
            t += s[i];
            if(st.find(t) != st.end()){
                backtrack(s, i+1, st, ans, curr + t + (i < s.length()-1 ? " ": ""));
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;

        unordered_set<string> st(wordDict.begin(), wordDict.end());

        backtrack(s, 0,st, ans, "");
        return ans;
    }
};
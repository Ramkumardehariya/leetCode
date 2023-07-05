class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastIndex(26, 0);

        for(int i = 0; i<s.size(); i++){
            lastIndex[s[i] - 'a'] = i;
        }

        vector<bool> vis(26, 0);
        stack<char> st;

        int i = 0;
        for(int i = 0; i<s.size(); i++){
            int curr = s[i]-'a';

            if(vis[curr]){
                continue;
            }

            while( st.size() > 0 && i<lastIndex[st.top() - 'a'] && st.top() > s[i]){
                vis[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            vis[curr] = true;
        }

        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
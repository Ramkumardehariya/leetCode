class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        queue<char> q;
        string ans = "";

        for(int i = 0; i<s.size(); i++){
            if(s[i] == ')'){
                while(st.top() != '('){
                    q.push(st.top());
                    st.pop();
                }
                st.pop();

                while(q.size() != 0){
                    st.push(q.front());
                    q.pop();
                }
            }
            else{
                st.push(s[i]);
            }
        }
        while(st.size() != 0){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
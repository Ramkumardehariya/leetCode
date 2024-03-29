class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1;
        stack<char> st2;

        for(int i = 0; i<s.size(); i++){
            if(s[i] == '#'){
                if(!st1.empty()){
                    st1.pop();
                }
            }
            else{
                st1.push(s[i]);
            }
        }


        for(int i = 0; i<t.size(); i++){
            if(t[i] == '#'){
                if(!st2.empty()){
                    st2.pop();
                }
            }
            else{
                st2.push(t[i]);
            }
        }

        string a = "";
        string b = "";

        while(!st1.empty()){
            a += st1.top();
            st1.pop();
        }

        while(!st2.empty()){
            b += st2.top();
            st2.pop();
        }

        if(a == b){
            return true;
        }
        return false;

    }
};
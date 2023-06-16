class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        char sign = '+';
        int curr = 0;

        for(int i = 0; i<s.length(); i++){
            if(isdigit(s[i])){
                curr = curr*10 + int(s[i]-'0');
            }
            if(!isdigit(s[i]) && s[i] != ' ' || i == s.length()-1){
                if(sign == '+'){
                    st.push(curr);
                }
                else if(sign == '-'){
                    st.push(-curr);
                }
                else{
                    int num;
                    if(sign == '*'){
                        num = st.top()*curr;
                    }
                    else{
                        num = st.top()/curr;
                    }
                    st.pop();
                    st.push(num);
                }
                sign = s[i];
                curr = 0;
            }
        }

        int sum = 0;

        while(!st.empty()){
            sum = sum + st.top();
            st.pop();
        }

        return sum;
    }
};
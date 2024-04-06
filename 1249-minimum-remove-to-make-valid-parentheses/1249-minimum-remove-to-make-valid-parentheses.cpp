class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open = 0;
        int close = 0;
        int flag = 0;

        for(char ch : s){
            if(ch == '('){
                open++;
                flag++;
            }
            if(ch == ')' && flag > 0){
                close++;
                flag--;
            }
        }
        int k = min(open, close);
        close = k; 
        open = k;
        string ans = "";

        for(char ch : s){
            if(ch == '('){ 
                if(open > 0){
                    ans += '(';
                    open--;
                }
                continue;
            }
            if(ch == ')' ){
                if(close > 0 && close > open){
                    ans += ')';
                    close--;
                }
                continue;
            }
            else{
                ans += ch;
            }
        }
        return ans;
    }
};
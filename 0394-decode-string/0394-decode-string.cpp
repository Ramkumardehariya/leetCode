class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        stack<string> str;

        string ans;
        int num = 0;

        for(auto ch : s){
            if(isdigit(ch)){
                num = num*10 + (ch-'0');
            }
            else if(ch == '['){
                nums.push(num);
                str.push(ans);

                num = 0;
                ans = "";
            }
            else if(ch == ']'){
                string temp = ans;
                ans = str.top();
                str.pop();
                for(int i = nums.top(); i>0; i--){
                    ans += temp;
                }
                nums.pop();
            }
            else {
                ans += ch;
            }
        }

        return ans;
    }
};
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string zero = "";
        string one = "";
        string ans = "";

        for(int i = 0; i<s.size(); i++){
            if(s[i] == '0'){
                zero += s[i];
            }
            else{
                one += s[i];
            }
        }

        if(one.size() > 1){
            ans += one;
        }
        if(ans.size() > 0){
            ans.erase(ans.size()-1);
        }

        ans += zero;
        ans += '1';

        return ans;
    }
};
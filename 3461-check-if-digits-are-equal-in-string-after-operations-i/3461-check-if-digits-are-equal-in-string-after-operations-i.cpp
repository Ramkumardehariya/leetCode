class Solution {
public:
    bool hasSameDigits(string s) {
        int i = 0;

        while(s.size() != 2){
            string temp = "";
            for(int i = 0; i<s.size()-1; i++){
                int num1 = s[i]-'0';
                int num2 = s[i+1]-'0';
                int sum = (num1+num2)%10;
                temp += sum+'0';
            }
            s = temp;
        }

        if(s[0] == s[1]){
            return true;
        }
        return false;
    }
};
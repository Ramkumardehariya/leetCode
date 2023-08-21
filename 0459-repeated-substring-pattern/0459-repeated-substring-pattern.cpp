class Solution {
public:
    bool repeatedSubstringPattern(string s) {
       
        string str = s+s;

        if(str.substr(1, str.length()-2).find(s) != -1){
            return true;
        }

        return false;
    }
};
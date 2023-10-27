class Solution {
public:

    bool check(int i , int j, string &s){
        while(i<j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int start = 0;
        int minlen = 0;

        for(int i = 0; i<s.size(); i++){
            for(int j = i; j<s.size(); j++){
                
                if(check(i,j,s)){
                    if(j-i+1 > minlen){
                        start = i;
                        minlen = j-i+1;
                    }

                }
            }
        }
        return s.substr(start,minlen);
    }
};
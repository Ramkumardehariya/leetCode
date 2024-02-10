class Solution {
public:

    bool isPalindrome(string s){
        int j = s.size()-1;
        int i = 0;

        // cout<<s<<" ";

        while(i<j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int ans = 0;

        for(int i = 0; i<s.size(); i++){
            for(int j = 1; j<=s.size()-i; j++){
                if(isPalindrome(s.substr(i,j))){
                    ans++;
                }
            }
        }

        return ans;
    }
};
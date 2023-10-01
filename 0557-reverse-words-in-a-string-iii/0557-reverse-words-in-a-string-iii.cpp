class Solution {
public:
    string reverseWords(string s) {
        string ans = "";

        int n = s.size();
        string temp = "";
        
        for(int i = 0; i<n; i++){
            if(s[i] == ' '){
                reverse(temp.begin(),temp.end());
                ans += temp;
                ans += ' ';
                temp = "";
            }
            else{
                temp += s[i];
            }
        }

        if(temp.size() > 0){
            reverse(temp.begin(), temp.end());
            ans += temp;
        }
        return ans;
    }
};
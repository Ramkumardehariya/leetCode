class Solution {
public:
    string reversePrefix(string word, char ch) {
        string ans = "";
        bool flag = true;
        int i = 0;

        for(; i<word.size(); i++){
            if(word[i] != ch){
                ans += word[i];
            }
            else if(word[i] == ch){
                ans += word[i];
                reverse(ans.begin(), ans.end());
                break;
            }
        }
        i++;

        for(; i<word.size(); i++){
            ans += word[i];
        }
        

        return ans;
    }
};
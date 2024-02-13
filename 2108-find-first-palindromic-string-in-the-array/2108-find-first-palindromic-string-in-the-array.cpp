class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        string ans = "";

        for(int i = 0; i<words.size(); i++){
            string temp = words[i];
            reverse(temp.begin(), temp.end());
            
            if(temp == words[i]){
                return temp;
            }
        }

        return ans;
    }
};
class Solution {
public:
    bool isSubsequence(string word, string temp){
        int i = 0;
        int j = 0;

        while(i < word.size() && j < temp.size()){
            if(word[i] == temp[j]){
                i++;
            }
            j++;
        }
        
        return i == word.size();
    }
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";

        for(auto word : dictionary){
            if(word.size() > ans.size() || (word.size() == ans.size() && word < ans)){
                if(isSubsequence(word, s)){
                    ans = word;
                }
            }
        }
        return ans;
    }
};
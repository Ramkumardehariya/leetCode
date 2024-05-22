class Solution {
public:

    bool palindrome(string s){
        int start = 0;
        int end = s.size()-1;

        while(start<=end){
            if(s[start] == s[end]){
                start++;
                end--;
            }
            else{
                return false;
            }
        }
        return true;
    }

    void solve(string s, vector<vector<string>> &ans, vector<string> temp){
        if(s.size() == 0){
            ans.push_back(temp);
        }

        for(int i = 0; i<s.size(); i++){
            string leftpart = s.substr(0, i+1);

            if(palindrome(leftpart)){
                temp.push_back(leftpart);
                solve(s.substr(i+1), ans, temp);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;

        solve(s, ans, temp);

        return ans;
    }
};
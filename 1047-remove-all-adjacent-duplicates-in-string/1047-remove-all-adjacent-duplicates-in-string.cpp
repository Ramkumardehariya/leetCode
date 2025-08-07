class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        int n = s.size();

        for(int i = 0; i<n; i++){
            int ch = s[i];

            if(ans.empty()){
                ans.push_back(ch);
            }
            else if(ch == ans.back()){
                ans.pop_back();
            }
            else if(ch != ans.back()){
                ans.push_back(ch);
            }
        }
        return ans;
    }
};
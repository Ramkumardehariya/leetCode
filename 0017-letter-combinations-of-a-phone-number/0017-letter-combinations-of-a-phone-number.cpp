class Solution {
public:
    
    void solve(int index,string output, string digits, string mapping[], vector<string> &ans){
        if(index >= digits.length()){
            ans.push_back(output);
            return;
        }

        int number = digits[index] - '0';
        string value = mapping[number];

        for(int i = 0; i<value.size(); i++){
            output.push_back(value[i]);
            solve(index+1, output, digits, mapping, ans);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        
        if(digits.length() == 0){
            return ans;
        }
        string output = "";
        int index = 0;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        solve(index, output,digits, mapping, ans);
        return ans;
    }
};
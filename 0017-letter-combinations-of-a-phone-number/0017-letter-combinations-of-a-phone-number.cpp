class Solution {
public:
    string arr[10] = {"","","abc","def","ghi","jkl","mno","pqrs", "tuv","wxyz"};

    void solve(vector<string> &ans, string temp, string digit, int index){
        if(index >= digit.size()){
            ans.push_back(temp);
            return;
        }

        int num = digit[index]-'0';
        string value = arr[num];

        for(int i = 0; i<value.size(); i++){
            temp.push_back(value[i]);
            solve(ans, temp, digit, index+1);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string temp = "";
        solve(ans, temp, digits, 0);
        return ans;
    }
};
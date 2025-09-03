class Solution {
public:
    void solve(string num1, string num2, string &ans,  int i, int j, int rem){
        if(i < 0 && j < 0 && rem == 0){
            return;
        }
        int first = 0;
        int second = 0;
        if(i >= 0){
            first = num1[i]-'0';
        }
        if(j >= 0){
            second = num2[j]-'0';
        }
        int sum = first + second + rem;
        int num = sum%10;
        rem = sum/10;
        ans += (num+'0');
        solve(num1, num2, ans, i-1, j-1, rem);
    }
    string addStrings(string num1, string num2) {
        string ans = "";
        solve(num1, num2,ans, num1.size()-1, num2.size()-1, 0);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
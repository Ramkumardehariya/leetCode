class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while(columnNumber){
            columnNumber--;
            int num = columnNumber%26;
            ans += char('A'+num);
            columnNumber /= 26;

        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
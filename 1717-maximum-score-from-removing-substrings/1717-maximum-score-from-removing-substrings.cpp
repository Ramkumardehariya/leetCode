class Solution {
public:
    int solve(string &s , int x, int y, string temp){
        int a = 0;
        int b = 0;
        int result = 0;

        for(int i = 0; i<s.size(); i++){
            if(s[i] == temp[0]){
                a++;
            }
            else if(s[i] == temp[1]){
                b++;
                if(a > 0){
                    result += x;
                    a--;
                    b--;
                }
            }
            else{
                result += min(a,b)*y;
                a = 0;
                b = 0;
            }
        }
        result += min(a,b)*y;
        return result;
    }
    int maximumGain(string s, int x, int y) {
        if(x > y){
            return solve(s, x, y, "ab");
        }
        else{
            return solve(s, y, x, "ba");
        }
    }
};
class Solution {
public:
    bool solve(string &s, int i, long long a, long long b, int n){
        if(i == s.size()){
            return n>2;
        }

        long long num = 0;

        for(int x = i; x<s.size(); x++){
            if(num > pow(10,17)){
                break;
            }
            num = num * 10 + s[x]-'0';

            bool check = false;

            if(n<2){
                check = solve(s, x+1, b, num, n+1);
            }
            else if(a+b == num){
                check = solve(s, x+1, b, num, n+1);
            }

            if(check){
                return true;
            }

            if(num == 0){
                break;
            }
        }
        return false;
    }
    bool isAdditiveNumber(string num) {
        return solve(num, 0, 0, 0, 0);
    }
};
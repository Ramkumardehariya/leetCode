class Solution {
public:
    int solve(int n){
        if(n <= 0){
            return 0;
        }
        if(n < 10){
            return 1;
        }
        int digits = floor(log10(n)) + 1;
        int base = pow(10,digits-1);        
        int rem = n%base;
        int firstdigit = n/base;
        int oneInbase;
        if(firstdigit == 1){
            oneInbase = n - base + 1;
        }
        else{
            oneInbase = base;
        }

        return solve(rem) + oneInbase + (firstdigit)*solve(base-1);
    }
    int countDigitOne(int n) {
        return solve(n);
    }
};
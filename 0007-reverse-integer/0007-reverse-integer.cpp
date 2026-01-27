class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        int neg = false;
        long long num = x;
        if(x < 0){
            neg= true;
            num = -(long long)x;
        }

        while(num > 0){
            int rem = num%10;
            ans = ans*10+rem;
            num = num/10;
        }
        if(ans > INT_MAX || ans < INT_MIN){
            return 0;
        }

        if(neg){
            ans = -ans;
        }
        return (int)ans;
    }
};
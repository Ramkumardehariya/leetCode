class Solution {
public:
    int reverse(int x) {

        long int ans = 0;

        while(x){
            int lastdigit = x % 10;

            ans = ans * 10 + lastdigit;

            x  = x/10;
        }

        if(ans > INT_MAX || ans < INT_MIN){
            return 0;
        }

        return ans;
    
    }
};
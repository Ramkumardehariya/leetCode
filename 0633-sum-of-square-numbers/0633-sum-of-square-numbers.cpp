class Solution {
public:
    bool judgeSquareSum(int c) {
        bool ans = false;
        if(c == 0){
            return true;
        }
        
        long long a = 0;
        long long b = sqrt(c);

        while(a <= b){

            long long sqrt = a*a + b*b;

            if(sqrt == c){
                return true;
            }
            else if(sqrt > c){
                b--;
            }
            else{
                a++;
            }
            
        }

        return false;
    }
};
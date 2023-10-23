class Solution {
public:
    bool isPowerOfFour(int n) {

        // if(n == 1){
        //     return 1;
        // }
        // if(n<=0){
        //     return 0;
        // }
        // return n%4 == 0 && isPowerOfFour(n/4);


        if(n <= 0){
            return false;
        }

        double logval = log10(n)/log10(4);
        return (logval-int(logval)) == 0;
    }
};
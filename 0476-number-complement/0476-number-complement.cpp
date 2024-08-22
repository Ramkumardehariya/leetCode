class Solution {
public:
    int findComplement(int num) {
        string str = "";

        while(num > 0){
            int rem = num%2;
            str += to_string(rem);
            num /= 2;
        }
        long long n = 1;
        int ans = 0;
        

        for(int i = 0; i<str.size(); i++){
            if(str[i] == '0'){
                ans = ans + n;
            }
            n = n*2;
        }
        return ans;
    }
};
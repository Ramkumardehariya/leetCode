class Solution {
public:
    int reverse(int num){
        int sum = 0;

        while(num != 0){
            int rem = num%10;
            sum = sum*10 + rem;
            num = num/10;
        }
        return sum;
    }
    int maximum69Number (int num) {
        int reverseNum = reverse(num);
        int ans = 0;
        bool flag = false;

        while(reverseNum != 0){
            int rem = reverseNum%10;
            if(rem == 6 && flag == false){
                rem = 9;
                flag = true;
            }
            ans = ans*10 + rem;
            reverseNum = reverseNum/10;
        }

        return ans;
    }
};
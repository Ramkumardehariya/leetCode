class Solution {
public:
    string largestGoodInteger(string num) {
        int maxi = -1;

        for(int i = 1; i<num.size()-1; i++){
            if(num[i] == num[i+1] && num[i] == num[i-1]){
                int temp = num[i]-'0';
                maxi = max(temp, maxi);
            }
        }

        string ans = "";
        if(maxi == -1){
            return ans;
        }

        for(int i = 0; i<3; i++){
            ans += (maxi+'0');
        }

        return ans;
    }
};
class Solution {
public:
    string dtb(int n){
        string ans = "";

        while(n > 0){
            int rem = n%2;
            ans += rem+'0';
            n = n/2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    int btd(string str){
        int ans = 0;
        int i = str.size()-1;
        long long prod = 1;

        while(i >= 0){
            if(str[i] == '1'){
                ans += prod;
            }
            prod *= 2;
            i--;
        }
        return ans;
    }
    int bitwiseComplement(int n) {
        string str = dtb(n);
        string temp ="";

        for(int i = 0; i<str.size(); i++){
            if(str[i] == '0'){
                temp += '1';
            }
            else{
                temp += '0';
            }
        }
        int ans = btd(temp);

        return ans;
    }
};
class Solution {
public:
    int myAtoi(string s) {
        if (s.size() == 0) {
            return 0;
        }
        int i = 0;
        while(i < s.size() && s[i]== ' '){
            i++;
        }
        
        s = s.substr(i);
        // cout<<s<<endl;
        
        int sign = +1;
        long ans = 0;

        if(s[0] == '-'){
            sign = -1;
        }
        int mini = INT_MIN;
        int maxi = INT_MAX;
        if(s[0] == '+' || s[0] == '-'){
            i = 1;
        }
        else{
            i = 0;
        }

        
        while(i < s.size()){
            if(s[i] == ' ' || !isdigit(s[i])){
                break;
            }
            ans= ans*10 + s[i]-'0';

            if(sign == -1 && -1*ans < mini){
                return mini;
            }
            if(sign == 1 && ans > maxi){
                return maxi;
            }
            i++;
        }
        return (int)sign*ans; 
    }
};
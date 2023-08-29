class Solution {
public:
    int bestClosingTime(string s) {
        int sum = 0;
        for(auto i: s){
            sum += (i=='Y');
        }
        int ans = 0, k = 0;
        int x = sum;
        for(int i = 0; i < s.length(); i++){
            if(s[i]=='N')k++;
            if(s[i]=='Y')sum--;
            if(sum+k<x){
                x = sum+k;
                ans = i+1;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int maxScore(string s) {
        int ans = 0;
        int zeros = 0;
        

        for(int i = 0; i<s.size()-1; i++){
            if(s[i] == '0'){
                zeros++;
            }
            int one = 0;
            for(int j = i+1; j<s.size(); j++){
                if(s[j] == '1'){
                    one++;
                }
            }

            if(one+zeros > ans){
                ans = one+zeros;
            }
        }

        return ans;
    }
};
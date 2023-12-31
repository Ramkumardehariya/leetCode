class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ans = INT_MIN;

        for(int i = 0; i<s.size(); i++){
            for(int j = i+1; j<s.size(); j++){
                if(s[i] == s[j]){
                    ans = max(ans, j-i-1);
                }
            }
        }

        if(ans == INT_MIN){
            return -1;
        }
        return ans;
    }
};
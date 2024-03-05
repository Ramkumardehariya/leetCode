class Solution {
public:
    int minimumLength(string s) {
        int l = 0;
        int n = s.size();
        int r = n-1;
        int count = 0;

        while(l < r && s[l] == s[r]){
            while(l < r && s[l] == s[r]){
                l++;
                count++;
            }
            l--;
            while(l < r && s[r] == s[l]){
                r--;
                count++;
            }
            r++;
            
            l++;
            r--;
        }

        return n-count;
    }
};
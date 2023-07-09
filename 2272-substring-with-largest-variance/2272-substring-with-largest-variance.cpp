class Solution {
public:


    int kadane(int x, int y, string &s){
        int ans = 0;
        int d = 0;
        int n = s.size();
        int ycnt = 0;
        for(int i = 0; i<n; i++){
            if(s[i]-'a' == x){
                d++;
            }
            else if(s[i] - 'a' == y){
                d--;
                ycnt = 1;
            }

            if(ycnt != 0){
                ans = max(ans, d);
            }
            else{
                ans = max(ans, d-1);
            }

            if(d < 0){
                ycnt = 0;
                d = 0;
            }
        }
        return ans;
    }
    int largestVariance(string s) {
        vector<int> temp(26, 0);
        int ans = 0;

        for(char &ch : s){
            temp[ch-'a']++;
        }

        for(int i = 0; i<25; i++){
            if(temp[i] == 0){
                continue;
            }
            for(int j = i+1; j<26; j++){
                if(temp[j] == 0){
                    continue;
                }
                int val = max(kadane(i, j, s), kadane(j, i, s));
                ans = max(ans, val);
            }
        }
        return ans;
    }
};
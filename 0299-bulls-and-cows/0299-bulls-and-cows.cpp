class Solution {
public:
    string getHint(string secret, string guess) {
        
        string ans = "";
        int n = secret.size();
        vector<int> g(10, 0);
        vector<int> s(10, 0);
        int bulls = 0;
        int cows = 0;

        for(int i = 0; i<n; i++){
            if(secret[i]==guess[i]){
                bulls++;
            }
            else{
                g[secret[i]-'0']++;
                s[guess[i]-'0']++;
            }
        }


        for(int i=0; i<10; i++){
            cows+=min(g[i],s[i]);
        }

        ans+= to_string(bulls);
        ans+='A';
        ans+= to_string(cows);
        ans+='B';

        return ans;
    }
};
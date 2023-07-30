class Solution {
public:

    string check(string &a, string &b){
        if(a.find(b) != string::npos){
            return a;
        }

        for(int i = min(a.size(), b.size()); i>=0; i--){
            if(a.substr(a.size()-i) == b.substr(0, i)){
                return a+b.substr(i);
            }
        }
        return a+b;
    }

    string solve(vector<string> &s){
        int n = s.size();

        string ans = "";

        for(int i= 0; i<n; i++){
            for(int j = 0; j<n; j++){
                for(int k = 0; k<n; k++){
                    if(i != j && j != k && k != i){
                        string s1 = check(s[i], s[j]);
                        string s2 = check(s1, s[k]);

                        if(ans.empty() || s2.size() < ans.size() || (s2.size() == ans.size() && s2 < ans)){
                            ans = s2;
                        }
                    }
                }
            }
        }
        return ans;
    }
    string minimumString(string a, string b, string c) {
        vector<string> temp = {a, b, c};

        return solve(temp);
    }
};
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s == goal){
            return true;
        }

        int n = s.size();
        for(int i = 0; i<n; i++){
            if(s == goal){
                return true;
            }
            char ch = s[0];
            s.erase(0,1);
            s += ch;
        }
        return false;
    }
};
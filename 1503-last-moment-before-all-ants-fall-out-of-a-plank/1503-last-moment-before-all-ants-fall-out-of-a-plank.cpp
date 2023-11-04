class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;
        
        for(int i = 0; i<left.size(); i++){
            ans = max(ans, abs(0-left[i]));
        }

        for(int j = 0; j<right.size(); j++){
            ans = max(ans, abs(n-right[j]));
        }

        return ans;
    }
};
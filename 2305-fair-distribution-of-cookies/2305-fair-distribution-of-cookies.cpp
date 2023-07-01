class Solution {
public:
    int ans;

    void solve(vector<int>& cookies, int index, vector<int> &bags){
        int k = bags.size();
        if(index == cookies.size()){

            int maxi = INT_MIN;
            for(int i = 0; i<k; i++){
                
                maxi = max(maxi, bags[i]);
            }

            ans = min(ans, maxi);
            return;
        }

        for(int i = 0; i<k; i++){
            bags[i] += cookies[index];
            solve(cookies, index+1, bags);
            bags[i] -= cookies[index];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        vector<int> bags(k, 0);
        ans = INT_MAX;

        solve(cookies, 0, bags);

        return ans;
    }
};
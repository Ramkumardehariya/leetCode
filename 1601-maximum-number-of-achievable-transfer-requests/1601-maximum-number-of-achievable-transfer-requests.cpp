class Solution {
public:
    int ans = 0; 
    void solve(int i, vector<vector<int>>& requests, int l, vector<int> &temp){
        if(i == requests.size()){
            for(auto a: temp)if(a != 0)return ;
            ans = max(ans,l);
            return ;
        }

        solve(i+1, requests, l, temp);
        temp[requests[i][0]]--;
        temp[requests[i][1]]++;
        solve(i+1, requests, l+1, temp);
        temp[requests[i][0]]++;
        temp[requests[i][1]]--;
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> temp(n, 0);
        solve(0, requests, 0, temp);
        return ans;
    }
};
class Solution {
public:

    bool dfs(unordered_map<string,vector<string>> &m,vector<string> &ans,string s, int n ){
        if(ans.size() == n+1){
            return true;
        }
        if(m[s].size() == 0){
            return false;
        }

        for(int i = 0; i<m[s].size(); i++){
            string temp = m[s][i];
            ans.push_back(temp);
            m[s].erase(m[s].begin() + i);
            bool x = dfs(m, ans, temp, n);

            if(x){
                return true;
            }
            m[s].insert(m[s].begin()+i, temp);
            ans.pop_back();
        }
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {

        sort(tickets.begin(),tickets.end());
        unordered_map<string,vector<string>> m;
        int n = tickets.size();

        for(int i = 0; i<n; i++){
            string key = tickets[i][0];
            string value = tickets[i][1];

            m[key].push_back(value);
        }

        vector<string> ans;
        ans.push_back("JFK");
        bool x = dfs(m,ans,"JFK", n);
        return ans;
    }
};
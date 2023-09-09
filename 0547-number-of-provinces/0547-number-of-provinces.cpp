class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<int> adj[], vector<bool> &vis){
        vis[node] = true;

        for(auto neibour : adj[node]){
            if(!vis[neibour]){
                dfs(neibour, isConnected, adj, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count = 0;
        vector<bool> vis(n, 0);

        for(int i = 0; i<n; i++){
            if(!vis[i]){
                count++;
                dfs(i, isConnected, adj, vis);
            }
        }

        return count;
    }
};
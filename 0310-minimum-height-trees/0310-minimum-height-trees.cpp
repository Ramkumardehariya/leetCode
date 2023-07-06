class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        vector<int> indegree(n,0);
        int m = edges.size();

        for(int i = 0; i<m; i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }

        vector<int> ans;
        queue<int> q;
        for(int i = 0; i<n; i++){
            if(indegree[i] == 1){
                q.push(i);
            }
        }

        while(!q.empty()){
            int m = q.size();
            ans.clear();

            for(int i = 0; i<m; i++){
                int node = q.front();
                q.pop();
                ans.push_back(node);

                for(auto neibour: adj[node]){
                    indegree[neibour]--;
                    if(indegree[neibour] == 1){
                        q.push(neibour);
                    }
                }
            }
        }
        if(n == 1){
            ans.push_back(0);
        }
        return ans;
    }
};
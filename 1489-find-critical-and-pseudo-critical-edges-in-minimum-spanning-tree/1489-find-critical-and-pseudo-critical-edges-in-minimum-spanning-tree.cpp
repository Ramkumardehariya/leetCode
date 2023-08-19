class Solution {
public:
    int minimax(vector<vector<pair<int,int>>> &g, int src, int dest){
        vector<int> dist(g.size(), 1e9);
        priority_queue<pair<int,int>> pq;
        pq.emplace(dist[src] = 0, src);

        while(!pq.empty()){
            auto [pri, u] = pq.top();
            pq.pop();

            if(-pri > dist[u]){
                continue;
            }
            for(auto &[v,w] : g[u]){
                if(u == src && v == dest){
                    continue;
                }
                if(dist[v] > max(dist[u], w)){
                    dist[v] = max(dist[u],w);
                    pq.emplace(-dist[v],v);
                }
            }
        }
        return dist[dest];
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> g(n);

        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            g[u].emplace_back(v,w);
            g[v].emplace_back(u,w);
        }

        vector<vector<int>> ans(2);

        for(int i= 0; i<edges.size(); i++){
            auto &node = edges[i];
            int u = node[0];
            int v = node[1];
            int w = node[2];
            int m = minimax(g, u, v);
            if(w < m){
                ans[0].push_back(i);
            }
            else if(w == m){
                ans[1].push_back(i);
            }
        }
        return ans;
    }
};
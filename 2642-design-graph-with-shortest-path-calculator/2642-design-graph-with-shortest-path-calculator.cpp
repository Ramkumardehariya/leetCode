class Graph {
public:
    vector<vector<vector<int>>> g;
    long long int solve(int s,int e,vector<long long int> &dist,vector<bool>& vis){
        if(s==e){
            return 0;
        }
        if(dist[s] < 1e11)return dist[s];
        if(vis[s]){
            return dist[s];
        }
        vis[s] = true;
        long long int d = 1e11;
        for(auto &i: g[s]){
            d = min(d,solve(i[0],e,dist,vis)+i[1]*1LL);
        }
        return dist[s] = d;
    }
    
    Graph(int n, vector<vector<int>>& edges) {
        g.resize(n);
        for(auto &i: edges){
            g[i[0]].push_back({i[1],i[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        g[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int s, int e) {
        vector<long long int> dist(g.size(),1e11);
        dist[s] = 0;
        vector<bool> v(g.size());
        priority_queue<vector<long long int>,vector<vector<long long int>>,greater<vector<long long int>>> pq;
        pq.push({0,s});
        while(!pq.empty()){
            vector<long long int> v = pq.top();
            pq.pop();
            for(auto &i: g[v[1]]){
                if(dist[i[0]]>dist[v[1]]+i[1]*1LL){
                    dist[i[0]]=dist[v[1]]+i[1]*1LL;
                    pq.push({dist[i[0]],i[0]});
                }
            }
        }
        if(dist[e]==1e11)return -1;
        return dist[e];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
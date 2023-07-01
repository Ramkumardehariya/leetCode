//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    bool detectCyclebfs(int src, vector<int> adj[], int vis[]){
        vis[src] = 1;
        
        queue<pair<int,int>> q;
        
        q.push({src, -1});
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            
            q.pop();
            
            for(auto neibour : adj[node]){
                if(!vis[neibour]){
                    vis[neibour] = 1;
                    q.push({neibour, node});
                }
                else if(parent != neibour){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool detectCycle(int node , int parent, vector<int> adj[], int vis[]){
        vis[node] = 1;
        
        for(auto neibour : adj[node]){
            if(!vis[neibour]){
                if(detectCycle(neibour, node, adj, vis)){
                    return true;
                }
            }
            else if(neibour != parent){
                return true;
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        
        int vis[V] = {0};
        
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                if(detectCycle(i,-1, adj, vis)){
                    return true;
                }
            }
            
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
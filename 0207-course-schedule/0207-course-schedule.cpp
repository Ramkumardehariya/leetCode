class Solution {
public:


    bool cycleDetectDFS(int node,unordered_map<int, list<int>> &adj, unordered_map<int,bool> &visited, unordered_map<int,bool> &dfsVisited ){
        visited[node] = true;
        dfsVisited[node] = true;

        for(auto neibour: adj[node]){
            if(!visited[neibour]){
                bool check = cycleDetectDFS(neibour,adj, visited, dfsVisited);
                if(check){
                    return true;
                }
            }
            else if(dfsVisited[neibour]){
                return true;
            }
        }

        dfsVisited[node] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> adj;

        for(int i = 0; i<prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[u].push_back(v);
        }

        unordered_map<int,bool> visited;
        unordered_map<int,bool> dfsVisited;

        for(int i = 0; i<numCourses; i++){
            if(!visited[i]){
                bool cycle = cycleDetectDFS(i,adj,visited,dfsVisited);
                if(cycle){
                    return false;
                }
            }
        }
        return true;
    }
};
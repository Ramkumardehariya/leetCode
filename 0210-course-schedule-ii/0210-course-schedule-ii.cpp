class Solution {
public:

    bool dfs(int node, unordered_map<int,bool> &visited, unordered_map<int,bool> &dfsVisited, unordered_map<int,list<int>> &adj, stack<int> &st){
        visited[node] = true;
        dfsVisited[node] = true;

        for(auto neibour : adj[node]){

            if(!visited[neibour]){
                bool chek = dfs(neibour, visited, dfsVisited, adj, st);

                if(chek){
                    return true;
                }
            }
            else if(dfsVisited[neibour]){
                return true;
            }
        }

        st.push(node);
        dfsVisited[node] = false;
        return false;
    }
  
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        unordered_map<int,list<int>> adj;

        for(int i = 0; i<prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[u].push_back(v);
        }

        stack<int> st;
        vector<int> ans;

        unordered_map<int,bool> visited;
        unordered_map<int,bool> dfsVisited;

        for(int i = 0; i<numCourses; i++){
            if(!visited[i]){
                bool check = dfs(i, visited, dfsVisited, adj, st);
                if(check){
                    return {};
                }
            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};
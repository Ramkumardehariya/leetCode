class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int ans = 0;
        int n = points.size();
        unordered_map<int,int> mp;

        vector<bool> vis(n,0);

        for(int i = 0; i<n; i++){
            mp[i] = INT_MAX;
        }
        mp[0] = 0;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        pq.push({0,0});

        while(!pq.empty()){
            auto [w, u] = pq.top();

            pq.pop();

            if(vis[u] || mp[u] < w){
                continue;
            }
            vis[u] = true;
            ans += w;

            for(int v = 0; v<n; v++){

                if(!vis[v]){
                    int newDist = abs(points[v][1] - points[u][1]) + abs(points[u][0]-points[v][0]);
                    if(newDist < mp[v]){
                        mp[v] = newDist;
                        pq.push({newDist, v});
                    }
                }
            }
        }
        return ans;
    }
};
class Solution {
    int n;
    vector<pair<int,int>>ans;
    vector<vector<int>>adj;
    vector<int>res;
    pair<int,int> solve(int node,int par){
        int res=0;
        int num=0;
        for(auto i:adj[node]){
            if(i==par)continue;
            auto p=solve(i,node);
            res+=p.first;
            num+=p.second;
        }
        
        return ans[node]={res+num,num+1};
    }
    void solve2(int node,int par){
        if(par==-1){
            res[node]=ans[node].first;
        }else{
            res[node]=res[par]-ans[node].second+(ans[0].second-ans[node].second);
        }
        for(auto i:adj[node]){
            if(i==par)continue;
            solve2(i,node);
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        this->n=n;
        adj.resize(n);
        ans.resize(n);
        res.resize(n);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        solve(0,-1);
        solve2(0,-1);
        return res;
    }
};
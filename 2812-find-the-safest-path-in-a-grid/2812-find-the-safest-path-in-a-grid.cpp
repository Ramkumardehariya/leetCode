class Solution {
public:
    
    vector<int>dx={0,-1,0,1};
    vector<int>dy={-1,0,1,0};
    bool check(int mid,vector<vector<int>>grid,vector<pair<int,int>>&t)
    {
        int n=grid.size();
        queue<pair<int,int>>q;
        for(int j=0;j<t.size();++j)
        {
             if(t[j].first+t[j].second<mid)
            {
                return false;
            }
        }
        if(mid==0)
        {
            return true;
        }
        q.push({0,0});
        grid[0][0]=1;
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();

          
            if(x==n-1&&y==n-1)
            {
                return true;
            }
            for(int i=0;i<4;++i)
            {
                int u=x+dx[i];
                int v=y+dy[i];

                if(u>=0&&u<n&&v>=0&&v<n&&grid[u][v]==0)
                {
                    bool flag=true;
                    for(int j=0;j<t.size();++j)
                    {
                
                      if(abs(u-t[j].first)+abs(v-t[j].second)<mid)
                        {
                            flag=false;
                            break;
                        }
                    }
                    if(flag)
                    {
                          q.push({u,v});
                    }
                     grid[u][v]=1;//we have checked this to mark that 
                }
            }
        }
        return false;
        
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        //we have to find the maximum manhattan distance through all the paths possible 
        //safest distance minimum limit is 0 as if go through the theif with no choice possible 
        //maximum safest distance 
      
        int n=grid.size();
          if(grid[0][0]==1||grid[n-1][n-1]==1)
              return 0;
        int left=0;
        int right=2*(n-1);
        int ans;
        vector<pair<int,int>>th;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(grid[i][j]==1)
                {
                    th.push_back({i,j});
                }
            }
        }
        while(left<=right)//as we are returning the maximum safest distance 
        {
            int mid=(left+right)/2;//assumed safest maximum distance 
            if(check(mid,grid,th))
            {
                ans=mid;
                left=mid+1;//trying to maximize the answer
            }
            else 
            {
                right=mid-1;
            }
            
        }
        return ans;
    
    }
};
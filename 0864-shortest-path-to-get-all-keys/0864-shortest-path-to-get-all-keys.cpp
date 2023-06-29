class Solution {
public:
int m,n;
bool check(int i,int j,vector<string>& grid){
    return i>=0 && i<m && j>=0 && j<n && grid[i][j]!='#';
}

    int shortestPathAllKeys(vector<string>& grid) {
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        m=grid.size();
        n=grid[0].size();
        int sx,sy,ans=0;
        int vis[30][30][64]={0};
        int maxi=-1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='@'){
                    sx=i;
                    sy=j;

                }
                else if(grid[i][j]>=65 && grid[i][j]<=90){
                    maxi=max(maxi,grid[i][j]-65);
                }
            }
        }
       
        queue<vector<int>>q;
        vis[sx][sy][0]=1;
        q.push({sx,sy,0});
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto it=q.front();
            q.pop();
            int x=it[0],y=it[1],cur=it[2];
            if(grid[x][y]>=97){
                cur=cur|(1<<(grid[x][y]-97));
            }

            if(((1<<(maxi+1)) -1)==cur)
            return ans;
            for(int i=0;i<4;i++){
                int xx=x+dx[i];
                int yy=y+dy[i];
                if(check(xx,yy,grid)){
                    if(grid[xx][yy]=='.'||grid[xx][yy]=='@'||grid[xx][yy] >=97){
                        if(!vis[xx][yy][cur]){
                            vis[xx][yy][cur]=1;
                            q.push({xx,yy,cur});
                        }

                    }
                    else if(grid[xx][yy]>=65){
                        int loc=grid[xx][yy]-'A';
                        if((cur & (1<<loc))!=0){
                            if(!vis[xx][yy][cur]){
                                vis[xx][yy][cur]=1;
                               q.push({xx,yy,cur});
                            }
                        }

                        
                    }
                }

            }

        }
        ans++;
                
            }
            
            return -1;
        
        
    }
};
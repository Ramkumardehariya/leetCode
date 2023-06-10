//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  
      void bfs(vector<vector<char>> &grid, vector<vector<int>> &vis, int row, int col){

        vis[row][col] = 1;

        queue<pair<int,int>> q;
        q.push({row, col});

        
        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int delrow = -1; delrow<=1; delrow++){
                for(int delcol = -1; delcol<=1; delcol++){
                    int row1 = x + delrow;
                    int col1 = y + delcol;

                    if(row1 >= 0 && row1 < n && col1 >= 0 && col1 < m && 
                    grid[row1][col1] == '1' && !vis[row1][col1]){
                            vis[row1][col1] = 1;
                            q.push({row1, col1});
                        }
                }
            }
        }
    }
    
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int> (m, 0));

        int count = 0;
        for(int row = 0; row<n; row++){
            for(int col = 0; col<m; col++){
                if(!vis[row][col] && grid[row][col] == '1'){
                    count++;
                    bfs(grid, vis, row, col);
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends
class Solution {
public:

    void solve(vector<vector<int>> &grid, int i, int j, int prev, vector<vector<int>>& ocean){
        if(i < 0 || j < 0 || i>=grid.size() || j>=grid[0].size()){
            return ;
        }
        if(ocean[i][j] == -1){
            return ;
        }
        if(grid[i][j] < prev){
            return;
        }

        ocean[i][j] = -1;
        solve(grid, i+1, j, grid[i][j], ocean);
        solve(grid, i-1, j, grid[i][j], ocean);
        solve(grid, i, j+1, grid[i][j], ocean);
        solve(grid, i, j-1, grid[i][j], ocean);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int n = heights.size();
        int m = heights[0].size();
        

        if(n == 0){
            return ans;
        }

        vector<vector<int>> pacific(n, vector<int> (m, 0));
        vector<vector<int>> atlantic(n, vector<int> (m, 0));

        for(int i =0; i<n; i++){
            solve(heights, i, 0, INT_MIN, pacific);
            solve(heights, i, m-1,INT_MIN, atlantic);
        }

        for(int j = 0; j<m; j++){
            solve(heights, 0, j, INT_MIN, pacific);
            solve(heights, n-1, j, INT_MIN, atlantic);
        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(pacific[i][j] == -1 && pacific[i][j] == atlantic[i][j]){
                    ans.push_back({i, j});
                }
            }
        }
        
        return ans;
    }
};
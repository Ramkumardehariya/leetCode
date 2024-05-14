class Solution {
public:
    int n = 0;
    int m = 0;
    int solve(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0){
            return 0;
        }
        int temp = grid[i][j];
        grid[i][j] = 0;
        
        int right = solve(grid, i+1, j);
        int down = solve(grid, i, j+1);
        int left = solve(grid, i-1, j);
        int up = solve(grid, i, j-1);

        grid[i][j] = temp;
        return temp+max(right, max(down, max(left, up)));
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int maxSum = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] > 0){
                    int sum = solve(grid, i, j);
                    maxSum = max(sum, maxSum);
                }
            }
        }
        return maxSum;
    }
};
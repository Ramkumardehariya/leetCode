class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int col = grid[0].size()-1;
        int row = 0;

        while(col > 0){
            int i = 0;
            int j = col;
            vector<int> temp;

            while(i < n && j < n){
                temp.push_back(grid[i][j]);
                i++;
                j++;
            }
            sort(temp.begin(), temp.end());

            
            i = 0;
            j = col;
            int k = 0;

            while(k < temp.size() && i < n && j < n){
                grid[i][j]= temp[k];
                i++;
                j++;
                k++;
            }
            col--;
        }

        while(row < n){
            int i = row;
            int j = 0;
            vector<int> temp;

            while(i < n && j < n){
                temp.push_back(grid[i][j]);
                i++;
                j++;
            }
            sort(temp.begin(), temp.end());

            i = row;
            j = 0;
            int k = temp.size()-1;

            while(k >= 0 && i < n && j < n){
                grid[i][j]= temp[k];
                i++;
                j++;
                k--;
            }
            row++;
        }
        return grid;
    }
};
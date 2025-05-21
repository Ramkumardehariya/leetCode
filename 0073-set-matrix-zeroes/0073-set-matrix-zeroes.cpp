class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> visited = matrix;

        for(int x = 0; x<m; x++){
            for(int y = 0; y<n; y++){
                if(matrix[x][y] == 0){
                    for(int z = 0; z<n; z++){
                        visited[x][z] = 0;
                    }
                }
            }
        }

        for(int x = 0; x<m; x++){
            for(int y = 0; y<n; y++){
                if(matrix[x][y] == 0){
                    for(int z = 0; z<m; z++){
                        visited[z][y] = 0;
                    }
                }
            }
        }

        for(int x = 0; x<m; x++){
            for(int y = 0; y<n; y++){
                matrix[x][y] = visited[x][y];
            }
        }


    }
};
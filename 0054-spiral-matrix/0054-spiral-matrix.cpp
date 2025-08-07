class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();

        int startRow = 0;
        int startCol = 0;
        int endRow = n-1;
        int endCol = m-1;

        int count = 0;
        int total = m*n;

        while(count < total){
            for(int j = startCol; count<total && j <= endCol; j++){
                ans.push_back(matrix[startRow][j]);
                count++;
            }
            startRow++;
            for(int j = startRow; count<total &&  j<=endRow; j++){
                ans.push_back(matrix[j][endCol]);
                count++;
            }
            endCol--;
            for(int j = endCol; count<total &&  j >= startCol; j--){
                ans.push_back(matrix[endRow][j]);
                count++;
            }
            endRow--;
            for(int j = endRow; count<total &&  j>= startRow; j--){
                ans.push_back(matrix[j][startCol]);
                count++;
            }
            startCol++;
        }
        return ans;
    }
};
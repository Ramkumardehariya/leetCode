class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int n = matrix.size();
        int m = matrix[0].size();

        int startRows = 0;
        int startCols = 0;
        int endRows = n-1;
        int endCols = m-1;

        while(startRows <= endRows && startCols <= endCols){

            for(int j = startCols; j <=endCols; j++){
                ans.push_back(matrix[startRows][j]);
            }
            startRows++;

            for(int i = startRows; i <= endRows; i++){
                ans.push_back(matrix[i][endCols]);
            }
            endCols--;

            for(int j = endCols; j>= startCols && startRows <= endRows; j--){
                ans.push_back(matrix[endRows][j]);
            }
            endRows--;

            for(int i = endRows; i>=startRows && startCols <= endCols; i--){
                ans.push_back(matrix[i][startCols]);
            }
            startCols++;
        }
        return ans;
    }
};
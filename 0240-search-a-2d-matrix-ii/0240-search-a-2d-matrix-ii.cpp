class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int row = 0;
        int col = m-1;

        while(col >= 0 && row >=0 && row < n && col < m){
            int num = matrix[row][col];

            if(num == target){
                return true;
            }
            if(num > target){
                col--;
            }
            else{
                row++;
            }
        }

        return false;
    }
};
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int s = 0;
        int e = m*n-1;

        while(s <= e){
            int mid = s+(e-s)/2;
            int num = matrix[mid/m][mid%m];

            if(num == target){
                return true;
            }
            else if(num > target){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }

        return false;
    }
};
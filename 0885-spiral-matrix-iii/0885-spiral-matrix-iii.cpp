class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {

        int directions[5] = {0,1,0,-1,0};
        vector<vector<int>> ans{{rStart,cStart}};
        int j = 0;
        int n = 0;

        while(ans.size() != rows*cols){
            for(int i = 0; i<n/2+1; i++){
                rStart += directions[j];
                cStart += directions[j+1];
                if(rStart < rows && rStart >= 0 && cStart < cols && cStart >= 0){
                    ans.push_back({rStart,cStart});
                }
            }
            n++;
            j = (j+1)%4;
        }
        return ans;
    }
};
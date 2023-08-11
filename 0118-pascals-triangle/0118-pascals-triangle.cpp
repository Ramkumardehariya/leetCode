class Solution {
public:

    int nCr(int n,int r){
        long long res = 1;

        for(int i = 0; i<r; i++){
            res = res *(n-i);
            res = res / (i+1);
        }
        return res;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for(int i = 1; i<=numRows; i++){
            vector<int> temp;
            for(int j = 1; j<=i; j++){
                int num = nCr(i-1, j-1);
                temp.push_back(num);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
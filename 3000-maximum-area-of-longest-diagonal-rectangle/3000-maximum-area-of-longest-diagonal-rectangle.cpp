class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans = 0;
        long double maxi = 0;


        for(int i= 0; i<dimensions.size(); i++){
            long double sqr = sqrt(dimensions[i][0]*dimensions[i][0] + dimensions[i][1]*dimensions[i][1]);
            int temp = dimensions[i][0]*dimensions[i][1];
            if(sqr >= maxi && ans < temp){
                maxi = sqr;
                ans = temp;
            }
        }
        return ans;
    }
};
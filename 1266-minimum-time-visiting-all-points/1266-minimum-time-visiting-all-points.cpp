class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        int maxi;

        for(int i = 0; i<points.size()-1; i++){
            int diff =  abs(points[i+1][0] - points[i][0]);
            int diff2 = abs(points[i+1][1] - points[i][1]);

            maxi = max(diff, diff2);
            ans += maxi;
        }

        return ans;
    }
};
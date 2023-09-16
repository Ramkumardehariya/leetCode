class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int ans = 0;
        int n = heights.size();
        int m = heights[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});

        vector<vector<int>> dir = {{0,-1}, {0, 1}, {-1,0}, {1,0}};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            ans = max(ans, it[0]);

            int i = it[1];
            int j = it[2];

            if(heights[i][j] == -1){
                continue;
            }

            if(i == n-1 && j == m-1){
                break;
            }

            for(int d = 0; d<4; d++){
                int newi = i + dir[d][0];
                int newj = j + dir[d][1];

                if(newi < 0 || newj < 0 || newi >= n || newj >= m){
                    continue;
                }

                pq.push({abs(heights[i][j] - heights[newi][newj]), newi, newj});
            }
            heights[i][j] = -1;
        }
        return ans;
        
    }
};
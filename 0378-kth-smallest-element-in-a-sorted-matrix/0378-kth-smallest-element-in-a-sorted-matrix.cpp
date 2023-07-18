class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> temp;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                temp.push_back(matrix[i][j]);
            }
        }

        priority_queue<int> pq;

        for(int i = 0; i<k; i++){
            pq.push(temp[i]);
        }

        for(int i = k; i<temp.size(); i++){
            if(temp[i] < pq.top()){
                pq.pop();
                pq.push(temp[i]);
            }
        }
        return pq.top();
    }
};
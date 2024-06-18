class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int ans = 0;

        for(int i = 0; i<worker.size(); i++){
            int index = -1;

            for(int j = 0; j<profit.size(); j++){
                if(worker[i] >= difficulty[j]){
                    if(index == -1){
                        index = j;
                    }
                    else if(profit[j] > profit[index]){
                        index = j;
                    } 
                }
            }
            if(index != -1){
                ans += profit[index];
            }

        }
        return ans;
    }
};
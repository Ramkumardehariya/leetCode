class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int n = costs.size();

        int s= 0;
        int e = n-1;

        while(s<candidates){
            pq.push({costs[s],s});
            s++;
        }

        while(s<e && e>=n-candidates){
            pq.push({costs[e], e});
            e--;
        }

        long long ans = 0;

        while(k--){
            auto top = pq.top();
            ans += top.first;
            pq.pop();

            if(e >= s){
                if(top.second > e){
                    pq.push({costs[e], e});
                    e--;
                }
                else{
                    pq.push({costs[s], s});
                    s++;
                }
            }
        }
        return ans;
    }
};
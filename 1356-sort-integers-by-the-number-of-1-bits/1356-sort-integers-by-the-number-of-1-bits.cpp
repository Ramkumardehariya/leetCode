class Solution {
public:
    int solve(int num){
        int count = 0;
        while(num != 0){
            int n = num%2;
            if(n == 1){
                count++;
            }
            num = num/2;
        }
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> ans;
        vector<int> temp;

        for(int i = 0; i<arr.size(); i++){
            int num = solve(arr[i]);
            temp.push_back(num); 
        }


        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(int i = 0; i<arr.size(); i++){
            pq.push({temp[i], arr[i]});
        }

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
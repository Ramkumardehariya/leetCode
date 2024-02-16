class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;

        for(auto it : arr){
            mp[it]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        for(auto it : mp){
            pq.push({it.second, it.first});
        }

        while(k != 0 ){
            auto it = pq.top();
            pq.pop();
            int num = it.first;
            num -= 1;

            if(num > 0){
                pq.push({num, it.second});
            }
            k = k - 1;
        }

        return pq.size();
    }
};
class Solution {
public:
    string frequencySort(string s) {
        // unordered_map<char, int> mp;
        // for(auto i : s){
        //     mp[i]++;
        // }
        // vector<pair<int,char>> temp;
        // for(auto it : mp){
        //     temp.push_back({it.second, it.first});
        // }
        // sort(temp.begin(), temp.end(), greater<pair<int,char>>());
        // string ans;

        // for(auto it : temp){
        //     for(int i= 0; i<it.first; i++){
        //         ans.push_back(it.second);
        //     }
        // }
        // return ans;

        unordered_map<char,int> mp;
        for(auto it: s){
            mp[it]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto it: mp){
            pq.push({it.second, it.first});
        }

        string ans = "";
        while(!pq.empty()){
            int freq = pq.top().first;
            while(freq){
                ans += pq.top().second;
                freq--;
            }
            pq.pop();
        }

        return ans;
    }
};
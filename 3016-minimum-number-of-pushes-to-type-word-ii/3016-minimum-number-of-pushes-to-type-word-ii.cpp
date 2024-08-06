class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;

        unordered_map<char,int> mp;

        for(int i = 0; i<word.size(); i++){
            mp[word[i]]++;
        }

        priority_queue<pair<int,char>> pq;

        for(auto it : mp){
            pq.push({it.second,it.first});
        }

        int count = 0;
        int mul = 1;

        while(!pq.empty()){
            count++;
            auto it = pq.top();
            ans += it.first * mul;
            if(count % 8 == 0){
                mul += 1;
            }
            pq.pop();
        }
        return ans;
    }
};
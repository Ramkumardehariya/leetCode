class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mp;
        priority_queue<pair<int,char>> pq;
        string ans = "";

        for(auto it : s){
            mp[it]++;
        }
        for(auto it : mp){
            pq.push({it.second, it.first});
        }

        while(pq.size() > 1){
            auto top1 = pq.top();
            pq.pop();

            auto top2 = pq.top();
            pq.pop();

            ans += top1.second;
            ans += top2.second;

            int num1 = top1.first-1;
            int num2 = top2.first-1;

            if(num1 > 0){
                pq.push({num1, top1.second});
            }
            if(num2 > 0){
                pq.push({num2, top2.second});
            }
        }

        if(!pq.empty()){
            if(pq.top().first > 1){
                return "";
            }
            else{
                ans += pq.top().second;
            }
        }
        
        return ans;
    }
};
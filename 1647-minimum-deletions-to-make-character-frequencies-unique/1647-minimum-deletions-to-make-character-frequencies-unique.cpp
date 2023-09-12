class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> mp;

        for(auto it : s){
            mp[it]++;
        }
        int ans = 0;

        unordered_set<int> st;

        for(auto it : mp){
            int temp = it.second;

            while(temp > 0 && st.find(temp) != st.end()){
                temp--;
                ans++;
            }

            if(temp != 0){
                st.insert(temp);
            }
        }

        return ans;
    }
};
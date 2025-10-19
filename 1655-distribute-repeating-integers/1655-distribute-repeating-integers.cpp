class Solution {
public:

    bool solve(vector<int> &quan, map<int,int> &mp, int i){
        if(i == quan.size()){
            return true;
        }

        for(auto it: mp){
            if(it.second >= quan[i]){
                mp[it.first] = it.second - quan[i];
                bool next = solve(quan, mp, i+1);
                if(next){
                    return true;
                }
                mp[it.first] = it.second;
            }
        }
        return false;
    }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        map<int,int> mp;
        for(auto num : nums){
            mp[num]++;
        }

        sort(quantity.begin(), quantity.end(), greater<int>());

        bool ans = solve(quantity, mp, 0);

        return ans;
    }
};
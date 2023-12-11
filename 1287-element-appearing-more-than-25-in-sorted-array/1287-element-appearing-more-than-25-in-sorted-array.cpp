class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int,int> mp;

        for(int i = 0; i<arr.size(); i++){
            mp[arr[i]]++;
        }
        int check = 0;
        int ans = 0;
        for(auto it : mp){
            if(it.second > check){
                check = it.second;
                ans = it.first;
            }
        }

        return ans;
    }
};
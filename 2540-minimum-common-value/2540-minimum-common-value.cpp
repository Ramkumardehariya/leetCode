class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        set<int> st;

        for(int it  : nums1){
            st.insert(it);
        }
        vector<int> num1(st.begin(), st.end());
        st.clear();

        for(int it  : nums2){
            st.insert(it);
        }
        vector<int> num2(st.begin(), st.end());
        st.clear();


        for(auto it : num1){
            mp[it]++;
        }
        for(auto it : num2){
            mp[it]++;
        }

        int ans = -1;

        for(auto it: mp){
            if((it.second >= 2 && ans == -1) || (it.second >= 2 && it.first < ans)){
                ans = it.first;
            }
        }

        return ans;
    }
};
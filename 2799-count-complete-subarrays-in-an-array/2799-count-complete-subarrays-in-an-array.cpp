class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        set<int> st;
        
        for(auto it : nums){
            st.insert(it);
        }
        int ans = 0;
        
        
        
        for(int i = 0; i<n; i++){
            vector<int> count(2001, 0);
            int cnt = 0;
            for(int j = i; j<n; j++){
                count[nums[j]]++;
                if(count[nums[j]] == 1){
                    cnt++;
                }
                if(st.size() == cnt){
                    ans++;
                }
            }
        }
        
        return ans;
    }
};
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> v(32, 0);
        int  n= nums.size();

        for(auto i : nums){
            for(int j = 0; j<32; j++){
                if(i&(1<<j)){
                    v[j]++;
                }
            }
        }

        int ans = 0;
        for(auto i : v){
            ans += (i*(n-i));
        }

        return ans;
    }
};
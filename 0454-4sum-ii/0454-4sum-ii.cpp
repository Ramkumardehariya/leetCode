class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int count = 0;
        unordered_map<int,int> mp;

        for(auto it1 : nums1){
            for(auto it2 : nums2){
                mp[it1+it2]++;
            }
        }

        for(auto it1 : nums3){
            for(auto it2: nums4){
                if(mp.count(0-it1-it2)){
                    count += mp[0-it1-it2];
                }
            }
        }
        return count;
    }
};
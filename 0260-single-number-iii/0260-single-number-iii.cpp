class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // unordered_map<int,int> map;
        // vector<int> ans;
        // for(int i = 0; i<nums.size(); i++){
        //     map[nums[i]]++;
        // }
        
        // for(auto it : map){
        //     if(it.second == 1){
        //         ans.push_back(it.first);
        //     }
        // }
        // return ans;

        long int x = 0;

        for(auto num : nums){
            x = x^num;
        }

        x = x&-x;
        int ans1 = 0;
        int ans2 = 0;

        for(auto num: nums){
            if(num&x){
                ans1 = ans1^num;
            }
            else{
                ans2 = ans2^num;
            }
        }

        return {ans1, ans2};
    }
};
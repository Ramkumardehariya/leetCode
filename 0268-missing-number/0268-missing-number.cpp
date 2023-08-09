class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x = 0;
        for(auto it : nums){
            x = x^it;
        }
        for(int i = 0;i<=nums.size(); i++){
            x = x^i;
        }

        return x;
    }
};
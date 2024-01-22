class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2,0);
        int n = nums.size();

        vector<int> temp(n+1,0);

        for(int i = 0; i<n; i++){
            temp[nums[i]]++;
        }

        for(int i = 0; i<temp.size(); i++){
            if(temp[i] == 0){
                ans[1] = i;
            }
            if(temp[i] > 1){
                ans[0] = i;
            }
        }

        return ans;
    }
};
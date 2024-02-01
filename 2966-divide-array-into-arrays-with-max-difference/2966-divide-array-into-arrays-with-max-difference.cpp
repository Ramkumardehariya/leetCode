class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());


        for(int i = 0; i<nums.size(); i++){
            if(temp.size() < 3){
                temp.push_back(nums[i]);
            }
            else if(temp.size() == 3){
                i--;
                ans.push_back(temp);
                temp.clear();
            }
        }

        if(temp.size() > 1){
            ans.push_back(temp);
        }

        bool flag = false;

        for(int i = 0; i<ans.size(); i++){
            if(ans[i][2]-ans[i][1] > k || ans[i][1]-ans[i][0] > k || ans[i][2]-ans[i][0] > k){
                flag = true;
                break;
            }
        }

        if(flag){
            ans.clear();
            return ans;
        }

        return ans;
    }
};
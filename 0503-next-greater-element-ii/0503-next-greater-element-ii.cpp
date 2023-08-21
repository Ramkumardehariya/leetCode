class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();

        for(int i = 0; i<n; i++){
            int j, check = 0;

            if(i == n-1){
                j = 0;
            }
            else{
                j = i+1;
            }

            for(; j<n; j++){
                if(nums[j] > nums[i]){
                    ans.push_back(nums[j]);
                    check = 1;
                    break;
                }
                if(j == n-1){
                    if(i == j){
                        break;
                    }
                    j = 0;
                    if(nums[j] > nums[i]){
                        ans.push_back(nums[j]);
                        check = 1;
                        break;
                    }
                }

                if(j == i){
                    break;
                }
            }

            if(check == 1){
                continue;
            }
            else{
                ans.push_back(-1);
            }
        }

        

        return ans;
    }
};
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        //TLE
        // int n = nums.size();
        // vector<int> ans;
        // int temp = 1;
        // for(int i = 0; i<n; i++){
        //     int num = nums[i];
        //     for(int j = 0; j<n; j++){
        //         if(j != i){
        //             temp = temp*nums[j];
        //         }
        //     }
        //     ans.push_back(temp);
        //     temp = 1;
        // }
        // return ans;

        
        int n = nums.size();
        vector<int> ans;
        int product = 1;
        
        for(int i = 0; i<n; i++){
            product = product*nums[i];
            ans.push_back(product);
        }

        product = 1;
        for(int i = n-1; i>0; i--){
            ans[i] = ans[i-1] * product;
            product = product*nums[i];
        }
        ans[0] = product;
        return ans;
        
    }
};
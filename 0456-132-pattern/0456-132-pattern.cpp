class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        
        // for(int i = 0; i < n; i++){
        //     for(int j = i+1; j<n; j++){
        //         for(int k = j+1; k<n; k++){
        //             if(nums[k] < nums[j] && nums[k] > nums[i]){
        //                 return true;
        //             }
        //         }
        //     }
        // }
        // return false;

        // int mini = nums[0];
        // for(int j = 0; j<n; j++){
        //     for(int k = j+1; k<n; k++){
        //         if(nums[k] > mini && nums[k] < nums[j]){
        //             return true;
        //         }
        //         mini = min(mini,nums[j]);
        //     }
        // }
        // return false;


        stack<int> st;
        int s3 = INT_MIN;
        for(int i = n-1; i>=0; i--){
            if(nums[i] < s3){
                return true;
            }
            else{
                while(!st.empty() && nums[i] > st.top()){
                    s3 = st.top();
                    st.pop();
                }
            }
            st.push(nums[i]);
        }
        return false;
    }
};
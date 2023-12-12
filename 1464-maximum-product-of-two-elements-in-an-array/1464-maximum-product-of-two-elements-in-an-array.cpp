class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> pq;

        for(auto it : nums){
            pq.push(it);
        }

        int i = pq.top();
        pq.pop();
        int j= pq.top();

        return (i-1)*(j-1);

        // int first = 0;
        // int index = 0;
        // int second = 0;

        // for(int i = 0; i<nums.size(); i++){
        //     if(nums[i] >= first){
        //         first = nums[i];
        //         index = i;
        //     }
        // }
        // for(int i = 0; i<nums.size(); i++){
        //     if(index != i && nums[i] > second){
        //         second = nums[i];
        //     }
        // }

        // return (first-1)*(second-1);
    }
};
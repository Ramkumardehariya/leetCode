class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int> pq;

        for(auto num: nums){
            pq.push(num);
        }

        int i = 1;

        while(pq.size() && i< n){
            nums[i] = pq.top();
            pq.pop();
            i+=2;
        }

        int j = 0;
        while(pq.size() && j<n){
            nums[j] = pq.top();
            pq.pop();
            j += 2;
        }
    }
};
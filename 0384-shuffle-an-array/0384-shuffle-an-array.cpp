class Solution {
public:
    vector<int> temp;
    Solution(vector<int>& nums) {
        temp = nums;
    }
    
    vector<int> reset() {
        return temp;
    }
    
    vector<int> shuffle() {
        int n = temp.size();

        vector<int> ans = temp;

        for(int i = 0; i<n; i++){
            int random = rand() % n;
            swap(ans[i], ans[random]);
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
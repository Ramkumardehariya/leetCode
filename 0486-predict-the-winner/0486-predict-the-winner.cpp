class Solution {
public:
    int solve(vector<int> &nums, int i , int j){
        if(i > j){
            return 0;
        }
        if(i == j){
            return nums[i];
        }

        int op1 = nums[i] + min(solve(nums, i+2, j), solve(nums, i+1, j-1));
        int op2 = nums[j] + min(solve(nums, i, j-2), solve(nums, i+1, j-1));

        return max(op1, op2);
    }
    bool predictTheWinner(vector<int>& nums) {
        int p1Score = solve(nums, 0, nums.size()-1);
        int totalSum = 0;
        for(int i = 0; i<nums.size(); i++){
            totalSum += nums[i];
        }
        int p2Score = totalSum-p1Score;

        return p1Score >= p2Score;
    }
};
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = size(nums);
       string res(n,' ');

    for(int i = 0; i < n; i++)
        res[i] = nums[i][i] == '0' ? '1' : '0';
    
    return res;
    }
};
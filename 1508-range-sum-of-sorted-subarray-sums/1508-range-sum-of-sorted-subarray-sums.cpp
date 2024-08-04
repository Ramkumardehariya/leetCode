class Solution {
public:
    int mod = 1000000007;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long> temp;

        for(int i = 0; i<nums.size(); i++){
            long sum = 0;
            for(int j = i; j<nums.size(); j++){
                sum += nums[j];
                temp.push_back(sum);
            }
        }
        sort(temp.begin(),temp.end());
        long ans = 0;

        int i = left-1;

        while(i < temp.size() && i < right){
            ans += temp[i];
            i++;
        }
            
        return ans%mod;
    }
};
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i<nums.size(); i++){
            int count = 0;
            int sum = nums[i];
            for(int j = 1; j*j<nums[i]; j++){
                if(nums[i]%j == 0){
                    int n = nums[i]/j;
                    count++;
                    sum += j;
                    if(nums[i] != n){
                        count++;
                        sum+=n;
                    }
                    if(count > 3){
                        break;
                    }
                }
            }
            if(count == 3){
                ans += sum;
            }
        }
        return ans;
    }
};
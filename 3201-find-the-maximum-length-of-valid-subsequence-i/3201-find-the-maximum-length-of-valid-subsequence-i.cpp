class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int even = 0;
        int odd = 0;
        int alt = 0;
        bool evenFlag = false;
        bool oddFlag = false;
        if(nums[0]%2 == 0){
            evenFlag = true;
        }
        else{
            oddFlag = true;
        }

        for(int i = 0; i<nums.size(); i++){
            if(nums[i]%2 == 0){
                even++;
            }
            else{
                odd++;
            }

            if(nums[i] % 2== 0 && evenFlag == true){
                alt++;
                evenFlag = false;
                oddFlag = true;
            }

            if(nums[i]%2 != 0 && oddFlag == true){
                alt++;
                evenFlag = true;
                oddFlag = false;
            }
        }

        return max(alt,max(even, odd));

    }
};
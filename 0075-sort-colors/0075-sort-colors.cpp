class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> temp(3,0);

        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 0){
                temp[0]++;
            }
            else if(nums[i] == 1){
                temp[1]++;
            }
            else{
                temp[2]++;
            }
        }

        int i = 0;
        for(int j = 0; j<3; j++){
            int num = temp[j];
            while(num != 0){
                nums[i] = j;
                i++;
                num--;
            }
        }
    }
};
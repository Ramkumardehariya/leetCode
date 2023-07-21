class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> list(n,1), count(n,1);
        int maxLen = 1;

        for(int i = 1; i<n; i++){
            for(int  j = 0; j<i; j++){
                if(nums[i] > nums[j]){
                    if(list[j]+1 > list[i]){
                        list[i] = list[j]+1;
                        count[i] = count[j];
                    }
                    else if(list[j]+1 == list[i]){
                        count[i] += count[j];
                    }
                }
            }
            maxLen = max(maxLen, list[i]);
        }

        int numOfLis = 0;

        for(int i = 0; i<n; i++){
            cout<<count[i]<<" ";
            if(list[i] == maxLen){
                numOfLis += count[i];
            }
        }

        return numOfLis;
    }
};
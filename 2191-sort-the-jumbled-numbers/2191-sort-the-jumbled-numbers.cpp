class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        const int m = nums.size();
        vector<pair<int,int>> mpp;
        vector<int> ans;
        for(int i=0;i<m;++i){
            int temp = nums[i];
            if(temp==0){mpp.push_back({mapping[0],i});continue;}
            int mapped = 0;
            int mul = 1;
            while(temp>0){
                mapped+=(mapping[(temp%10)]*mul);
                mul*=10;
                temp/=10;
            }
            mpp.push_back({mapped,i});
        }
        sort(mpp.begin(),mpp.end());
        for(int i=0;i<m;++i){ans.push_back(nums[mpp[i].second]);}
        return ans;
    }
};
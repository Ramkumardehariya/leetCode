#define pr pair<int,int>
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        priority_queue<pr,vector<pr>,greater<pr>>q;
        
        for(int i=0;i<nums.size();i++){
            q.push({nums[i],i});
        }
        
        int ans=INT_MIN;
        int i=0,j=nums.size()-1;
        
        while(i<=k && j>=k){
            auto ele=q.top();
            int mini= ele.first;
            int ind = ele.second;
            q.pop();
            
            ans=max(ans,mini*(j-i+1));
            
            if(ind>=k && ind<=j){
                j=ind-1;
            }
            
            else if(ind<=k && ind>=i){
                i=ind+1;
            }
        }
        
        return ans;
    }
};
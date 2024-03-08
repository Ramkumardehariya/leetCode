class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(int i = 0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        priority_queue<int> pq;

        for(auto it : mp){
            pq.push(it.second);
        }

        int ans = 0;
        int num = pq.top();
        ans += num;
        pq.pop();
        bool flag = true;

        while(flag == true && !pq.empty()){
            if(pq.top() == num){
                ans += pq.top();
                pq.pop();
            }
            else{
                flag = false;
                break;
            }
        }

        return ans;
    }
};
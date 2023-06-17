class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        //TC= O(n), SC=O(1)
        // sort(nums.begin(),nums.end());
        // int n = nums.size();
        // int cap = n/3;
        // int count = 1;
        // set<int> s;
        // for(int i = 0; i<n; i++){
        //     int num = nums[i];
        //     for(int j = i+1; j<n; j++){
        //         if(num == nums[j]){
        //             count++;
        //         }
        //         else{
        //             i = j-1;
        //             break;
        //         }
        //     }
        //     if(count > cap){
        //         s.insert(num);
        //     }
        //     count = 1;
        // }
        // vector<int> ans(s.begin(),s.end());


        // TC=O(n) , SC=O(n)
        // unordered_map<int,int> map;
        // vector<int> ans;
        // int n = nums.size();
        // int cap = n/3+1;
        // for(int i = 0 ; i<n; i++){
        //     map[nums[i]]++;
        //     if(cap == map[nums[i]]){
        //         ans.push_back(nums[i]);
        //     }
        // }

        // TC=O(n) , SC=O(1)
        int n = nums.size();
        int cap = n/3;
        int count1 = 0;
        int count2 = 0;
        int ele1 = INT_MIN;
        int ele2 = INT_MIN;
        vector<int> ans;
        for(int i = 0; i<n; i++){
            if(count1 == 0 && ele2 != nums[i]){
                count1 = 1;
                ele1 = nums[i];
            }
            else if(count2 == 0 && ele1 != nums[i]){
                count2 = 1;
                ele2 = nums[i];
            }
            else if(nums[i] == ele1){
                count1++;
            }
            else if(nums[i] == ele2){
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for(int i = 0; i<n; i++){
            if(ele1 == nums[i]){
                count1++;
            }
            if(ele2 == nums[i]){
                count2++;
            }
        }
        if(count1 > cap){
            ans.push_back(ele1);
        }
        if(count2 > cap){
            ans.push_back(ele2);
        }

        return ans;
    }
};
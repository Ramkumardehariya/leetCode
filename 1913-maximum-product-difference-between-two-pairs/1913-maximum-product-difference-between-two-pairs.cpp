class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        priority_queue<int> ans;

        for(int i = 0; i < nums.size(); i++){
            ans.push(nums[i]);
        }


        int n1 = ans.top();
        ans.pop();
        int n2 = ans.top();
        int i = 0;
        int n3 = 0;
        int n4 = 0;
        

        while(!ans.empty()){
            if(ans.size() == 2){
                n3 = ans.top();
                ans.pop();
                n4 = ans.top();
                
            }
            ans.pop();
        }

        return (n1*n2)-(n3*n4);
    }
};
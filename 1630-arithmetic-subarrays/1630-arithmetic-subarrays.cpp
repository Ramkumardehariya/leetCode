class Solution {
public:

    bool isArithmatic(vector<int> temp){

        if(temp.size() < 2){
            return true;
        }
        int num = temp[1]-temp[0];
        int count = 1;

        for(int i = 1; i<temp.size(); i++){
            if(temp[i]-temp[i-1] != num){
                return false;
            }
        }
       

        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {

        int n = l.size();
        vector<bool> ans(n);

        for(int i = 0; i<n; i++){
            vector<int> temp; 

            for(int j = l[i]; j<=r[i]; j++){
                temp.push_back(nums[j]);
            }

            sort(temp.begin(), temp.end());

            ans[i] = isArithmatic(temp);

        }

        return ans;
    }
};
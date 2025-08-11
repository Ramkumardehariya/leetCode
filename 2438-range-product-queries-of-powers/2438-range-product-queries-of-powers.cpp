class Solution {
public:
    int mod = 1000000007;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {

        vector<int> power;
        
        int cal = 1;
        while(n != 0){
            if(n&1 == 1){
                power.push_back(cal);
            }
            cal = cal*2;
            n = n>>1;
        }


        vector<int> ans;
        for(int i = 0; i<queries.size(); i++){
            int left = queries[i][0];
            int right = queries[i][1];
            int sum = 1;
            for(int j = left; j<=right; j++){
                sum = (sum*power[j])%mod;
            }
            ans.push_back(sum%mod);
        }
        return ans;
    }
};
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector<int> temp(n,1);

        for(int i = 0; i<n-1; i++){
            if(ratings[i] < ratings[i+1]){
                temp[i+1] = temp[i]+1;
            }
        }

        for(int i = n-2; i>=0; i--){   
            if(ratings[i] > ratings[i+1]){
                if(temp[i] > temp[i+1]){
                    continue;
                }
                else{
                    temp[i] = temp[i+1]+1;
                } 
            }
        }

        int ans = 0;
        for(int i = 0; i<temp.size(); i++){
            ans += temp[i];
        }

        return ans;
    }
};
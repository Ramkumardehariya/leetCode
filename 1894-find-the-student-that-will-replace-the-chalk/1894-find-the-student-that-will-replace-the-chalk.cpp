class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        vector<long> temp(n,0);
        long sum = 0;

        for(int i = 0; i<n; i++){
             sum += chalk[i];
             temp[i] = sum;
        }


        while(k > temp[n-1]){
            k = k-temp[n-1];
        }
        int ans = -1;
        for(int i = 0; i<n; i++){
            cout<<temp[i]<<" ";
            if(k == temp[i] && i == n-1){
                ans = 0;
                break;
            }
            else if(k == temp[i]){
                ans = i+1;
                break;
            }
            else if(k < temp[i]){
                ans = i;
                break;
            }
        }
        return ans;
    }
};
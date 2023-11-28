class Solution {
public:
    int mod = 1e9 + 7;
    int numberOfWays(string corridor) {
        int count = 0;
        long long ans = 1;
        int c = 0;

        for(int i = 0; i<corridor.size(); i++){
            if(corridor[i] == 'S'){
                count++;
            }
        }

        if(count == 0 || count%2){
            return 0;
        }

        for(int i= 0; i<corridor.size(); i++){
            if(corridor[i] == 'S'){
                c++;
            }

            if(c == 2){
                i++;
                int count = 1;
                while(i < corridor.size() && corridor[i] == 'P'){
                    i++;
                    count++;
                }
                if(i == corridor.size()){
                    break;
                }
                ans = (ans * count)%mod;
                c=0;
                i--;
            }
        }
        return ans;
    }
};
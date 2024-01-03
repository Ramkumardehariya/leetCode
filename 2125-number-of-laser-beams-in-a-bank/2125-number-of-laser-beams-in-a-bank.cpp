class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        int ans = 0;
        bool flag1 = 0;
        bool flag2 = 0;

        int one = 0;
        int two = 0;

        for(int i = 0; i<bank.size()-1; i++){

            if(flag1 == 0){
                for(int j = 0; j<bank[i].size(); j++){
                    if(bank[i][j] == '1'){
                        one++;
                    }
                }
            }

            if(flag2 == 0){
                for(int j = 0; j<bank[i+1].size(); j++){
                    if(bank[i+1][j] == '1'){
                        two++;
                    }
                }
            }
            
            if(one == 0 && two == 0){
                flag1 = 0;
                flag2 = 0;
            }
            else if(one != 0 && two == 0){
                flag1 = 1;
                flag2 = 0;
            }
            else if(one != 0 && two != 0){
                ans += (one*two);
                flag1 = 0;
                flag2 = 0;
                one = 0;
                two = 0;
            }
            else if(one == 0 && two != 0){
                flag1 = 0;
                flag2 = 0;
                one = 0;
                two = 0;
            }

        }

        return ans;
    }
};
class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int start1 = 0;
        int start0 = 0;

        for(int i = 0; i<s.size(); i++){
            if(i%2  == 0){
                if(s[i] == '0'){
                    start1++;
                }
                else{
                    start0++;
                }
            }
            else{
                if(s[i] == '0'){
                    start0++;
                }
                else{
                    start1++;
                }
            }
        }

        return min(start1,start0);
    }
};
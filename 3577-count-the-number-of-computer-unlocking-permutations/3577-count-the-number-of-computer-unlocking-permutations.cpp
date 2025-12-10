class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        long long ans =1;
        long long MOD = 1000000007;
        int Max_len=complexity.size();

        // first checking computer 0 is strictly simpler than others
        for (int i=1;i<Max_len;i++){

            // first case 
            /*
            if the 0 cant unlock i , and as 0 is the root , so we cant unlock i
            */
            if (complexity[i]<=complexity[0]){
                return 0;
            }

            /*
            2nd case else , you can calculate in another window or inside other for loop;
            but i am doing inside the same to save a huge time 

            and as 0 can unlock everyone so remaining is n-1 
            and as they can be unlocked in any order so total ways will be (n-1)! (factorial)
            */
           ans=(ans*i)%MOD;

        }

        return (int) ans;

    }
};
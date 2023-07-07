class Solution {
public:

    int solve(string str, int k, int ch){
        int mx = 0;
        int change = 0;
        int n = str.size();
        int i = 0;
        int j = 0;

        while(j<n){
            if(str[j] == ch){
                change++;
            }

            while(i<=j && change > k){
                if(str[i] == ch){
                    change--;
                }
                i++;
            }
            mx = max(j-i+1, mx);
            j++;
        }
        return mx;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {

        return max(solve(answerKey, k, 'T'), solve(answerKey, k, 'F'));
    }
};
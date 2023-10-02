class Solution {
public:
    bool winnerOfGame(string colors) {
        int count1 = 0;
        int count2 = 0;
        int n = colors.size();

        for(int i = 1; i<n-1; i++){
            if(colors[i-1] == 'A' && colors[i] == 'A' && colors[i+1] == 'A'){
                count1++;
            }
            else if(colors[i] == 'B' && colors[i-1] == 'B' && colors[i+1] == 'B'){
                count2++;
            }
        }

        return count1 > count2;
    }
};
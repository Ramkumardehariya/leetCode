class Solution {
public:
    int characterReplacement(string s, int k) {
        int tail = 0;
        int ans = 0;
        int count[26] = {0};

        for(int head = 0; head<s.size(); head++){

            count[s[head]-'A']++;

            while(head-tail+1- *max_element(count, count+26) > k){
                count[s[tail]-'A']--;
                tail++;
            }
            ans = max(ans, head-tail+1);
            
        }
        return ans;
    }
};
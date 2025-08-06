class Solution {
public:
    int compress(vector<char>& chars) {
        int count = 0;
        int i = 0;
        int ansIndex = 0;
        int n = chars.size();

        while(i < n){
            int j = i+1;

            while(j < n && chars[i] == chars[j]){
                j++;
            }
            count = j-i;
            chars[ansIndex++] = chars[i];

            if(count > 1){
                string cnt = to_string(count);
                for(auto ch : cnt){
                    chars[ansIndex++] = ch;
                }
            }
            i = j;
        }
        return ansIndex;
    }
};
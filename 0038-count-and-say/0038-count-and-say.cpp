class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";

        for(int i = 2; i<=n; i++){

            string temp = ans;
            int n = ans.size();
            int j = 0;
            ans = "";

            while(j<n){
                
                int count = j;
                while(j<n && temp[j] == temp[count]){
                    count++;
                }
                
                ans += to_string(count-j) + temp[j];
                j = count;
            }

        }
        return ans;

    }
};
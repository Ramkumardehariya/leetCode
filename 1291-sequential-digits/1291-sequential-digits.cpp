class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string s = "123456789";

        for(int i = 0; i<s.size(); i++){
            string temp = "";
            for(int j = i; j<s.size(); j++){
                temp += s[j];
                int num = stoi(temp);
            

                if(low <= num && high >= num){
                    ans.push_back(num);
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
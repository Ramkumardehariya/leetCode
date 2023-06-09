class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;

        unordered_map<string,int> temp;

        if(s.size() < 10){
            return ans;
        }

        for(int i = 0; i<=s.length()-10; i++){
            string str = s.substr(i,10);
            temp[str]++;
        }

        for(auto it : temp){
            if(it.second > 1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
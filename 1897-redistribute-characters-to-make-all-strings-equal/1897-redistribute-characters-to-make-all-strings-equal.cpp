class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> temp(26,0);

        for(int i = 0; i<words.size(); i++){
            for(int j = 0; j<words[i].size(); j++){
                temp[words[i][j]-'a']++;
            }
        }

        for(auto it : temp){
            if(it%words.size()){
                return false;
            }
        }
        return true;
    }
};
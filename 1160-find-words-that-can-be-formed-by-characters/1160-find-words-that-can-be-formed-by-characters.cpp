class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans = 0;

        for(int i = 0; i<words.size(); i++){
            int count = 0;
            string temp = chars;
            cout<<temp<<" ";
            for(int j = 0; j<words[i].size(); j++){
                
                for(int k = 0; k<temp.size(); k++){
                    if(words[i][j] == temp[k]){
                        temp.erase(temp.begin()+k);
                        count++;
                        break;
                    }
                }
            }
            if(count == words[i].size()){
                ans += words[i].size();
            }
        }
        return ans;
    }
};
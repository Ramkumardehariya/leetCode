class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int ans = 0;

        vector<string> arr;
        string temp = "";

        for(int i = 0; i<text.size(); i++){
            if(text[i] != ' '){
                temp += text[i];
            }
            else{
                arr.push_back(temp);
                temp = "";
            }
        }
        if(temp.size() > 0){
            arr.push_back(temp);
        }

        for(int i = 0; i<arr.size(); i++){
            bool flag = true;
            for(int j = 0; j<arr[i].size(); j++){
                for(int k = 0; k<brokenLetters.size(); k++){
                    if(brokenLetters[k] == arr[i][j]){
                        flag = false;
                        break;
                    }
                }
                if(flag == false){
                    break;
                }
            }
            if(flag){
                ans++;
            }
        }
        return ans;
    }
};
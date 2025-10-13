class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        ans.push_back(words[0]);

        for(int i = 1; i<words.size(); i++){
            int arr1[26] = {0};
            int arr2[26] = {0};

            for(int j = 0; j<words[i-1].size(); j++){
                arr1[words[i-1][j]-'a']++;
            }

            for(int j = 0; j<words[i].size(); j++){
                arr2[words[i][j]-'a']++;
            }

            bool flag = false;

            for(int j = 0; j<26; j++){
                if(arr1[j] != arr2[j]){
                    flag = true;
                    break;
                }
            }
            if(flag){
                ans.push_back(words[i]);
            }

        }

        return ans;
    }
};
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        int arr[26] = {0};
        int arr1[26] = {0};

        for(int i = 0; i<s.size(); i++){
            arr[s[i]-'a']++;
        }

        for(int i = 0;i<s.size(); i++){
            arr1[t[i]-'a']++;
              
        }
        for(int i = 0; i<26; i++){
            if(arr1[i] != arr[i]){
                return false;
            }
        }
        return true;
    }
};
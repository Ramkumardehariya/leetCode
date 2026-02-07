class Solution {
public:

    bool isSame(int *first, int *second){

        for(int i = 0; i<26; i++){
            if(first[i] != second[i]){
                return false;
            }
        }

        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()){
            return false;
        }
        int first[26] = {0};
        int second[26] = {0};

        for(int i = 0; i<s1.size(); i++){
            first[s1[i]-'a']++;
            second[s2[i]-'a']++;
        }

        int i = 0;

        for(int j = s1.size(); j<s2.size(); j++){
            if(isSame(first, second)){
                return true;
            }
            second[s2[i]-'a']--;
            second[s2[j]-'a']++;
            i++;
        }

        return false;
    }
};
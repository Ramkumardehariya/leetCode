class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int arr1[26] = {0};
        int arr2[26] = {0};

        if(s1.size() > s2.size()){
            return false;
        }

        for(auto ch: s1){
            arr1[ch-'a']++;
        }
        for(int i = 0; i<s1.size(); i++){
            arr2[s2[i]-'a']++;
        }

        if(arr1 == arr2){
            return true;
        }

        int i = 0;
        int j = s1.size();
        int n = s2.size();

        while(j < n){

            arr2[s2[i]-'a']--;
            arr2[s2[j]-'a']++;

            if(arr1 == arr2){
                return true;
            }
            
            bool flag = true;
            for(int i = 0;i<26; i++){
                if(arr1[i] != arr2[i]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                return true;
            }
            i++;
            j++;
        }

        return false;
    }
};
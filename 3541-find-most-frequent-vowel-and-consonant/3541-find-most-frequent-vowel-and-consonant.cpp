class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> mp;

        for(int i = 0; i<s.size(); i++){
            mp[s[i]]++;
        }

        int max1 = 0;
        int max2 = 0;

        for(auto it: mp){
            if( (it.first == 'a' || it.first == 'e' || it.first == 'i' || it.first == 'o' || it.first == 'u')&& (max1 < it.second)){
                
                max1 = it.second;
            }
            else if( (it.first != 'a' && it.first != 'e' && it.first != 'i' && it.first != 'o' && it.first != 'u') && (max2 < it.second)){
                max2 = it.second;
            }
        }
        return max1 + max2;
    }
};
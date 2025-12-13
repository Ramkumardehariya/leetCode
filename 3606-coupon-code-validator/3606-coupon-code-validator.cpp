class Solution {
public:
    bool isValid(string &str){
        if(str.size() == 0){
            return false;
        }

        for(int i = 0; i<str.size(); i++){
            if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'Z') ||  (str[i] == '_') ) {
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {

        vector<string> ans;
        map<string,vector<string>> mp;
        int n = code.size();

        for(int i = 0; i<n; i++){
            if(isValid(code[i]) && isActive[i] == true && (businessLine[i] == "restaurant" || businessLine[i] == "grocery" || businessLine[i] == "pharmacy" || businessLine[i] == "electronics")){
                mp[businessLine[i]].push_back(code[i]);
            }
        }

        for(auto it: mp){
            sort(it.second.begin(), it.second.end());
            for(auto temp: it.second){
                ans.push_back(temp);
            }
        }
        
        return ans;
    }
};
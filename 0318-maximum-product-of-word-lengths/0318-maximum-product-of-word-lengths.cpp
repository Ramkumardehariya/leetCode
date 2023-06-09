class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<set<int>> v;
        // int n = words.size();

        for(int i = 0; i<words.size(); i++){
            set<int>s;
            for(int j = 0; j<words[i].size(); j++){
                s.insert(words[i][j] - 'a');
            }
            v.push_back(s);
        }

        int ans = 0;
        int flag = 0;

        for(int i = 0; i<words.size(); i++){
            
            for(int j = 0; j<i; j++){
                for(auto it: v[i]){
                    if(v[j].find(it) != v[j].end()){
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0){
                    int p = words[i].size()*words[j].size();
                    ans = max(ans, p);
                }
                flag = 0;
            }
        }
        return ans;
    }
};
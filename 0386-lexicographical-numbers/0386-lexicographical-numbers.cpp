class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        vector<string> temp;

        for(int i = 1; i<=n; i++){
            temp.push_back(to_string(i));
        }

        sort(temp.begin(), temp.end());
        
        for(int i = 0; i<temp.size(); i++){
            ans.push_back(stoi(temp[i]));
        }
        
        return ans;

    }
};
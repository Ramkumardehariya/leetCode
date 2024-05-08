class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> temp = score;
        sort(temp.begin(), temp.end());
        int n = score.size();
        unordered_map<int,int> mp;
        int count = 1;

        for(int i = n-1; i>=0; i--){
            mp[temp[i]] = count;
            count++;
        }

        string first = "Gold Medal";
        string second = "Silver Medal";
        string third = "Bronze Medal";
        

        vector<string> ans;

        for(int i = 0; i<score.size(); i++){
            int num = score[i];
            for(auto it : mp){
                bool flag = false;
                if(it.first == num){
                    if(it.second == 1){
                        ans.push_back(first);
                    }
                    else if(it.second == 2){
                        ans.push_back(second);
                    }
                    else if(it.second == 3){
                        ans.push_back(third);
                    }
                    else{
                        ans.push_back(to_string(it.second));
                    }
                    flag = true;
                }
                if(flag){
                    break;
                }
            }
        }
        return ans;
    }
};
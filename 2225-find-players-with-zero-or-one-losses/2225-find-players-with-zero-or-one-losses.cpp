class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans;

        set<int> winner;
        set<int> loser;
        
        unordered_map<int,int> mp2;
        set<int> temp1;

        for(int i = 0; i<matches.size(); i++){
            temp1.insert(matches[i][0]);
            mp2[matches[i][1]]++;
        }
        vector<int> temp2(temp1.begin(), temp1.end());

        for(auto it : mp2){
            if(it.second == 1){
                loser.insert(it.first);
                mp2[it.first]++;
            }
        }

        for(int i = 0; i<temp2.size(); i++){
            mp2[temp2[i]]++;
        }

        for(auto it : mp2){
            if(it.second == 1){
                winner.insert(it.first);
            }
        }



        vector<int> w1(winner.begin(),winner.end());
        vector<int> l1(loser.begin(), loser.end());

        ans.push_back(w1);
        ans.push_back(l1);

        return ans;
    }
};
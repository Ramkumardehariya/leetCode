class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0;

        vector<pair<pair<int,int>,int>> store;

        for(int i = 0; i<mat.size(); i++){
            for(int j = 0; j<mat[0].size(); j++){
            
                store.push_back({{i,j},mat[i][j]});
                
            }
        }

        for(int i = 0; i<mat.size(); i++){
            for(int j = 0; j<mat[0].size(); j++){
            
                if(mat[i][j] == 1){
                    bool flag = true;
                    for(int k = 0; k<store.size(); k++){
                        int row = store[k].first.first;
                        int col = store[k].first.second;
                        int num = store[k].second;

                        if(row == i && j != col && num == 1){
                            flag = false;
                            break;
                        }

                        if(col == j && i != row && num == 1){
                            flag = false;
                            break;
                        }
                    }
                    if(flag){
                        ans++;
                    }
                }
                
            }
        }


        return ans;
    }
};
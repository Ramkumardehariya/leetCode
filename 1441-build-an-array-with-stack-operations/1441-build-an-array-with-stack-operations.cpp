class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int m = target.size();
        vector<int> temp;
        int j = 0;

        for(int i = 1; i<=target[m-1]; i++){
            if(j < target.size() && i == target[j]){
                temp.push_back(i);
                j++;
            }
            else if(j < target.size()){
                temp.push_back(-1);
            }
        }

        for(int i = 0; i<temp.size(); i++){
            if(temp[i] > 0){
                ans.push_back("Push");
            }
            else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;

    }
};
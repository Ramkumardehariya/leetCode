class Solution {
public:
    int countSeniors(vector<string>& details) {
        vector<string> temp;
        string str = "";

        for(int i = 0; i<details.size(); i++){
            str += details[i][11];
            str += details[i][12];
            temp.push_back(str);
            str.clear();
        }

        int ans = 0;

        for(int i = 0; i<temp.size(); i++){
            int num = stoi(temp[i]);
            if(num > 60){
                ans++;
            }
        }

        return ans;
    }
};
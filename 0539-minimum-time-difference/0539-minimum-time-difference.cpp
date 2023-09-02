class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> minutes;

        for(int i= 0; i<n; i++){
            string str = timePoints[i];

            int hour = stoi(str.substr(0,2));
            int minute = stoi(str.substr(3));
            int total = hour*60 + minute;
            minutes.push_back(total);
        }

        sort(minutes.begin(),minutes.end());

        int mini = INT_MAX;

        for(int i = 0; i<minutes.size()-1; i++){
            mini = min(mini,minutes[i+1]-minutes[i]);
        }

        mini = min(mini, minutes[0]+1440 - minutes[minutes.size()-1]);

        return mini;
    }
};
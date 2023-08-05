class Solution {
public:

    int find1(vector<vector<int>>& intervals, int start, int key){

        int temp = -1;
        int end = intervals.size()-1;
        
        while(start <= end){
            int mid = start + (end-start)/2;

            if(intervals[mid][0] >= key){
                temp = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return temp;
    }
    vector<int> findRightInterval(vector<vector<int>>& intervals) {

        int n = intervals.size();

        vector<int> ans(n, 0);
        

        for(int i = 0; i<n; i++){
            intervals[i].push_back(i);
        }

        sort(intervals.begin(), intervals.end());

        for(int i  = 0; i<n; i++){
            int curr = intervals[i][2];
            int next = find1(intervals, i, intervals[i][1]);
            if(next == -1){
                ans[curr] = -1;
            }
            else{
                ans[curr] = intervals[next][2];
            }
        }
        return ans;
    }
};
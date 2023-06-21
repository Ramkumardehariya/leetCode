class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int i = 0;

        while(i<n){
            if(n-i > citations[i]){
                i++;
            }
            else{
                break;
            }
        }
        return n-i;
    }
};
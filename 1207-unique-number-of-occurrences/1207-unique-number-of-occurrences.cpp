class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> ans;

        set<int> st;
        int count = 1;
        sort(arr.begin(), arr.end());

        for(int i = 0; i<arr.size()-1; i++){
            if(arr[i] == arr[i+1]){
                count++;
            }
            else{
                int s = st.size();
                st.insert(count);
                if(s == st.size()){
                    return false;
                }
                count = 1;
            }
        }
        int s = st.size();
        st.insert(count);
        if(s == st.size()){
            return false;
        }
        
        return true;
    }
};
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const unsigned int MOD = 1000000007;
        int n = arr.size();
        vector<int> pse(n), nse(n);
        stack<int> st;
        int ans = 0;

        st.push(0);
        for(int i = 1; i<n; i++){
            while(!st.empty() && arr[i] < arr[st.top()]){
                nse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()){
            nse[st.top()] = n;
            st.pop();
        }

        st.push(n-1);
        for(int i = n-2; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                pse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            pse[st.top()] = -1;
            st.pop();
        }

        for(int i = 0; i<n; i++){
            ans = ans%MOD + ((arr[i]%MOD) * (nse[i]-i) * (i-pse[i]))%MOD;
        }

        return ans%MOD;
    }
};
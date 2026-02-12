class Solution {
public:
    void prevSmaller(vector<int> &prev, vector<int> &heights){
        stack<int> st;
        st.push(-1);

        for(int i = 0; i<heights.size(); i++){
            int curr = heights[i];
            while(st.top() != -1 && heights[st.top()] >= curr){
                st.pop();
            }
            prev[i] = st.top();
            st.push(i);
        }
    }
    void nextSmaller(vector<int> &next, vector<int> &heights){
        stack<int> st;
        st.push(-1);

        for(int i = heights.size()-1; i>=0; i--){
            int curr = heights[i];
            while(st.top() != -1 && heights[st.top()] >= curr){
                st.pop();
            }
            next[i] = st.top();
            st.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> prev(n, 0);
        vector<int> next(n, 0);

        prevSmaller(prev, heights);
        nextSmaller(next, heights);
        int ans = 0;

        for(int i = 0; i<n; i++){
            int l = heights[i];
            if(next[i] == -1){
                next[i] = n;
            }
            int b = next[i]-prev[i]-1;
            int area = l*b;
            ans = max(ans, area);
        }
        return ans;
    }
};
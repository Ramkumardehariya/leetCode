class Solution {
public:
    vector<int> temp;
    Solution(vector<int>& w) {
        for(auto ind : w){
            if(temp.empty()){
                temp.push_back(ind);
            }
            else{
                temp.push_back(ind+temp.back());
            }
        }
    }
    
    int pickIndex() {
        int ind = rand() % temp.back();
        int left = 0;
        int right = temp.size()-1;
        while(left <= right){
            int mid = (left+right)/2;
            if(temp[mid] > ind){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return left;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int count = 0;
        string ans;

        for(int i = 0; i<arr.size(); i++){
            bool flag = true;

            for(int j = 0; j<arr.size(); j++){
                if(i != j && arr[i] == arr[j]){
                    flag = false;
                    break;
                }
            }
            if(flag == true){
                count++;
            }
            if(count == k){
                ans = arr[i];
                break;
            }
        }
        return ans;
    }
};
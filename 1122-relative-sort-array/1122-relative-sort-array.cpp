class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        unordered_map<int,int> mp;
        sort(arr1.begin(), arr1.end());

        for(auto it : arr1){
            mp[it]++;
        }

        for(int i = 0; i<arr2.size(); i++){
            for(auto it : mp){
                if(it.first == arr2[i]){
                    int num = it.second;
                    while(num != 0){
                        ans.push_back(it.first);
                        num--;
                    }
                }
            }
        }

        for(int i = 0; i<arr1.size(); i++){
            bool flag = true;
            for(int j= 0; j<arr2.size(); j++){
                if(arr2[j] == arr1[i]){
                    flag = false;
                    break;
                }
            }
            if(flag == true){
                ans.push_back(arr1[i]);
            }
        }

        return ans;
    }
};
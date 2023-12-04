class Solution {
public:
    string largestGoodInteger(string num) {
        priority_queue<string> pq;

        for(int i = 1; i<num.size()-1; i++){
            if(num[i-1] == num[i] && num[i] == num[i+1]){
                string temp = "";
                temp += num[i];
                temp += num[i-1];
                temp += num[i+1];

                pq.push(temp);
            }
        }
        if(pq.empty()){
            return "";
        }

        return pq.top();
    }
};
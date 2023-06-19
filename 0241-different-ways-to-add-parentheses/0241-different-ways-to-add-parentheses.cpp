class Solution {
public:
    
    vector<int> diffWaysToCompute(string expression) {

        vector<int> ans;

        for(int i = 0; i<expression.size(); i++){
            char curr = expression[i];

            if(curr == '*' || curr == '+' || curr == '-'){

                vector<int> left, right;

                left = diffWaysToCompute(expression.substr(0, i));

                right = diffWaysToCompute(expression.substr(i+1));


                for(auto j: left){
                    for(auto k: right){
                        if(curr == '*'){
                            ans.push_back(j*k);
                        }
                        else if(curr == '+'){
                            ans.push_back(j+k);
                        }
                        else{
                            ans.push_back(j-k);
                        }
                    }
                }
            }
        }
        if(ans.empty()){
            ans.push_back(stoi(expression));
        }
        return ans;
    }
};
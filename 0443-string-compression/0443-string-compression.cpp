class Solution {
public:
    int compress(vector<char>& chars) {
        int count = 1;
        int ans = 0;
        vector<char> temp;

        for(int i = 1; i<chars.size(); i++){
            if(chars[i-1] == chars[i]){
                count++;
            }
            else{
                if(count > 1 ){
                    temp.push_back(chars[i-1]);
                    vector<char> temp2;
                    while(count != 0){
                        int rem = count%10;
                        count = count/10;
                        temp2.push_back(rem+'0');
                    }
                    reverse(temp2.begin(), temp2.end());
                    for(int k = 0; k<temp2.size(); k++){
                        temp.push_back(temp2[k]);
                    }
                }
                else{
                    temp.push_back(chars[i-1]);
                }
                count = 1;
            }
        }
        if(count > 1 ){
                    temp.push_back(chars[chars.size()-1]);
                    vector<char> temp2;
                    while(count != 0){
                        int rem = count%10;
                        count = count/10;
                        temp2.push_back(rem+'0');
                    }
                    reverse(temp2.begin(), temp2.end());
                    for(int k = 0; k<temp2.size(); k++){
                        temp.push_back(temp2[k]);
                    }
                }
        else{
            temp.push_back(chars[chars.size()-1]);
        }
                chars = temp;
        return temp.size();
    }
};
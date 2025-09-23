class Solution {
public:
    int compareVersion(string version1, string version2) {
        long long num1 = 0;
        queue<long long> q1;
        queue<long long> q2;

        for(int i = 0; i<version1.size(); i++){
            if(version1[i] != '.'){
                num1 = num1*10+version1[i]-'0';
            }
            else{
                q1.push(num1);
                num1 = 0;
            }
        }

        if(num1 != 0){
            q1.push(num1);
        }
        num1 = 0;

        for(int i = 0; i<version2.size(); i++){
            if(version2[i] != '.'){
                num1 = num1*10+version2[i]-'0';
            }
            else{
                q2.push(num1);
                num1 = 0;
            }
        }

        if(num1 != 0){
            q2.push(num1);
        }

        while(!q1.empty() && !q2.empty()){
            long long n1 = q1.front();
            long long n2 = q2.front();
            q1.pop();
            q2.pop();

            if(n1 > n2){
                return 1;
            }
            else if(n1 < n2){
                return -1;
            }
        }

        
        while(!q1.empty() && q1.front() == 0){
            q1.pop();
        }

        while(!q2.empty() && q2.front() == 0){
            q2.pop();
        }


        if(!q1.empty() && q2.empty()){
            return 1;
        }
        else if(q1.empty() && !q2.empty()){
            return -1;
        }
        

        return 0;
    }
};
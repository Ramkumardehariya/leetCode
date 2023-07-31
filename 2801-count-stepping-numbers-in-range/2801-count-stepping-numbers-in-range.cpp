int mod=1000000007;

class Solution {
    vector<vector<int> > dp;
    
    long long findSteppingCnt(string &num){
        int n=num.length(),i,j,k,m,len;
        long long res=0;
        
        // Counting for smaller length numbers
        for(len=1;len<n;len++){
            for(j=1;j<10;j++){
                res+=dp[len][j];
                res=res%mod;
            }
        }
        
        //
        // Counting when startDigit is smaller for the same length number
        int startDigit = num[0]-'0';
        for(j=1;j<startDigit;j++){
            res+=dp[n][j];
            res=res%mod;
        }
        
        //
        // Counting when startDigit is as given for the same length number
        //    excluding the same number
        int currDigit, prevDigit=startDigit;
        for(i=1;i<n;i++){
            currDigit=num[i]-'0';
            len=n-i;
            
            if(prevDigit>0 && (currDigit > prevDigit-1)){
                  res+=dp[len][prevDigit-1];
                  res=res%mod;
            }
            if(prevDigit<9 && (currDigit > prevDigit+1)){
                res+=dp[len][prevDigit+1];
                res=res%mod;
            }
            if(abs(currDigit - prevDigit)==1){
                prevDigit=currDigit;
            }
            else{
                break;
            }
        }
        return res;
    }
    
    int isStepping(string &num){
        char prevDigit = num[0]-1, currDigit;
        for(auto &currDigit:num){
            if(abs(currDigit-prevDigit)!=1)return 0;
            prevDigit=currDigit;
        }
        return 1;
    }
public:
    Solution():dp(101,vector<int> (10,0))
    {
        int d,len=1;
        for(d=0;d<10;d++){
            dp[len][d]=1;
        }
        for(len=2;len<101;len++){
            dp[len][0]=dp[len-1][1];
            for(d=1;d<9;d++){
                dp[len][d]=(dp[len-1][d-1]+dp[len-1][d+1])%mod;
            }
            dp[len][9]=dp[len-1][8];
        }
    }
    int countSteppingNumbers(string &low, string &high) {
        return (findSteppingCnt(high)-findSteppingCnt(low) + isStepping(high) + mod)%mod;
        
    }
};
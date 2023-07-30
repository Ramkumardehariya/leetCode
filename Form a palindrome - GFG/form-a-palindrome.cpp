//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:


    int solve(int n , string s1, string s2){
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        
        for(int i = 1; i<n+1; i++){
            for(int j = 1; j<n+1; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[n][n];
    }
    int findMinInsertions(string S){
        int n = S.size();
        
        string s1 = S;
        reverse(S.begin(), S.end());
        string s2 = S;
        
        int lps = solve(n, s1, s2);
        
        return n-lps;
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.findMinInsertions(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends
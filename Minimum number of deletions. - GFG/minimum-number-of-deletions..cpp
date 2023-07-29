//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends


int solve(string s1, string s2, int n){
    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
    
    for(int i = 1; i<n+1; i++){
        for(int j = 1; j<n+1; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    
    return dp[n][n];
}
int minDeletions(string str, int n) { 
    string s1 = str;
    reverse(str.begin(), str.end());
    string s2 = str;
    
    int lps = solve(s1, s2, n);
    
    return n-lps;
}
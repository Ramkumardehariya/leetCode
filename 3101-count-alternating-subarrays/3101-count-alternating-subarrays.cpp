class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& a) {
        long long ans=0;
        long long cnt=1;
        long long curr=a[0];
        int n=a.size();
        for (int i=1;i<n;i++){
            if (a[i]!=curr){
                curr=1-curr;
                cnt++;
            }
            else{
                ans+=(cnt*(cnt+1))/2;
                cnt=1;
                curr=a[i];
            }
        }
        ans+=(cnt*(cnt+1))/2;
        return ans;
    }
};
class Solution {
    int solve(int num){
        int ans = 0;
        while(num > 0){
            ans++;
            num &= (num-1);
        }
        return ans;
    }
    public int minBitFlips(int start, int goal) {
        int diffNum = (start^goal);
        return solve(diffNum);
    }
}
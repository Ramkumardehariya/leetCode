class Solution {
    public int maximumLength(String s) {
        int n = s.length();
        char[] ch = s.toCharArray();

        int low=0, high=n-1;
        // Binary Search
        while(high>low){
            int mid = (low+high)/2;
            if(check(ch,mid)) low = mid+1;
            else high = mid;
        }
        // Returning low-1 as we have checked for size mid if true than set low = mid+1
        return low-1;
    }

    public boolean check(char[] ch, int len){
        // Arrays to store occcurance to each character
        int[] oc = new int[26];
        int count = 1;
        char prev = '.';
        for(int i=0;i<ch.length;i++){
            if(ch[i]!=prev){
                prev = ch[i];
                count = 1;
            }
            else{
                count++;
            }
            //Increment occurance of character if count >=len and check if Occurance has reched 3
            if(count>=len && ++oc[ch[i]-'a']>2){
                return true;
            }
        }
        return false;
    }
}
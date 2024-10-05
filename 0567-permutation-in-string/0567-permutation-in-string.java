class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int n = s1.length();
        int m = s2.length();
        if(n > m){
            return false;
        }

        int[] temp1 = new int[26];
        int[] temp2 = new int[26];

        for(int i = 0; i<n; i++){
            temp1[s1.charAt(i)-'a']++;
            temp2[s2.charAt(i)-'a']++;
        }

        for(int i = n; i<m; i++){
            if(Arrays.equals(temp1, temp2)){
                return true;
            }
            temp2[s2.charAt(i)-'a']++;
            temp2[s2.charAt(i-n)-'a']--;
        }

        return Arrays.equals(temp1, temp2);
    }
}
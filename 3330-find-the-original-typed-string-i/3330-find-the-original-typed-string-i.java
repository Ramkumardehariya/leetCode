class Solution {
    public int possibleStringCount(String word) {
        int []temp = new int[26];

        for(int i = 0; i<word.length(); i++){
            if(temp[word.charAt(i)-'a'] >= 1 && word.charAt(i) != word.charAt(i-1)){
                continue;
            }
            temp[word.charAt(i)-'a']++;
        }

        int ans = 1;

        for(int i = 0; i<26; i++){
            if(temp[i] > 1){
                ans += (temp[i]-1);
            }
        }
        return ans;
    }
}
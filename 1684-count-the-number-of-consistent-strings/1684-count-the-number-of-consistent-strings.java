class Solution {
    public int countConsistentStrings(String allowed, String[] words) {
        int ans = 0;

        for(String it : words){
            boolean flag = true;
            for(int i = 0; i<it.length(); i++){
                if(allowed.indexOf(it.charAt(i)) == -1){
                    flag = false;
                    break;
                }
            }
            if(flag == true){
                ans++;
            }
        }
        return ans;
    }
}
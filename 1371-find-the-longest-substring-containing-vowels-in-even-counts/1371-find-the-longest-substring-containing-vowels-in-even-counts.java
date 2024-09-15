class Solution {
    public int findTheLongestSubstring(String s) {
        HashMap<Integer,Integer> mp = new HashMap<>();
        mp.put(0,-1);

        int count = 0;
        int ans = 0;

        for(int i = 0; i<s.length(); i++){
            if(s.charAt(i) == 'a' || s.charAt(i) == 'e' || s.charAt(i) == 'i' || s.charAt(i) == 'o' || s.charAt(i) == 'u'){
                count ^= (1 << ((int)(s.charAt(i)-'a')));
            }
            if(mp.containsKey(count)){
                ans = Math.max(ans, i-mp.get(count));
            }
            else{
                mp.put(count,i);
            }
        }

        return ans;
    }
}
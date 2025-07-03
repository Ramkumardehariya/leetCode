class Solution {
    public char kthCharacter(int k) {
        String word = "a";

        while(word.length() < k){
            String temp = word;
            for(int i = 0; i<word.length(); i++){
                if(word.charAt(i) == 'z'){
                    temp += 'a';
                }
                else{
                    temp += (char)(word.charAt(i)+1);
                }
            }
            // System.out.println(temp);
            word = temp;
        }
        return word.charAt(k-1);
    }
}